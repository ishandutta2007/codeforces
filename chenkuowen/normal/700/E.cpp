#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
namespace __SEG{
	struct Node{
		int s[2];
	}t[N*20];
	int top=0;
	inline int new_node(){
		t[++top]=(Node){{0,0}};
		return top;
	}
	int merge(int x,int y){
		if(x==0||y==0) return x+y;
		int z=new_node();
		for(int i=0;i<2;++i)
			t[z].s[i]=merge(t[x].s[i],t[y].s[i]);
		return z;
	}
	int change(int p,int l,int r,int x){
		if(x<l||r<x) return p;
		int p1=new_node();
		if(l==r) return p1;
		int m=l+r>>1;
		t[p1].s[0]=change(t[p].s[0],l,m,x);
		t[p1].s[1]=change(t[p].s[1],m+1,r,x);
		return p1;
	}
	bool query(int p,int l,int r,int x,int y){
		if(y<l||r<x||p==0) return false;
		if(x<=l&&r<=y) return true;
		int m=l+r>>1;
		return query(t[p].s[0],l,m,x,y)||query(t[p].s[1],m+1,r,x,y);
	}
	int search(int p,int l,int r){
		if(p==0) return -1;
		if(l==r) return l;
		int m=l+r>>1;
		int k=search(t[p].s[0],l,m);
		if(k!=-1) return k;
		else return search(t[p].s[1],m+1,r);
	}
	template<int L,int R>struct SEG{
		int rt;
		SEG(int _rt=0){ rt=_rt; }
		SEG<L,R> insert(int x){ return __SEG::change(rt,L,R,x); }
		SEG<L,R> merge(SEG<L,R> b){ return __SEG::merge(rt,b.rt); }
		bool query(int x,int y){ return __SEG::query(rt,L,R,x,y); }
		int search(){ return __SEG::search(rt,L,R); }
	};
}
using __SEG::SEG;
struct SAM{
	struct Node{
		int s[26],fa,max;
	}t[N*2];
	int top;
	inline int new_node(){
		t[++top]=(Node){{},0,0};
		return top;
	}
	void init(){ top=-1,new_node(),new_node(); }
	SAM(){init();}
	int split(int p,int c){
		int d=t[p].s[c];
		if(t[d].max==t[p].max+1) return d;
		int q=new_node(); t[q].max=t[p].max+1;
		memcpy(t[q].s,t[d].s,sizeof(t[d].s));
		t[q].fa=t[d].fa,t[d].fa=q;
		for(;p>0&&t[p].s[c]==d;p=t[p].fa) t[p].s[c]=q;
		return q;
	}
	int extend(int p,int c){
		if(t[p].s[c]!=0) return split(p,c);
		int x=new_node(); t[x].max=t[p].max+1;
		for(;p>0&&t[p].s[c]==0;p=t[p].fa) t[p].s[c]=x;
		if(p==0) t[x].fa=1;
		else t[x].fa=split(p,c);
		return x;
	}
};
struct EXSAM{
	SAM sam;
	SEG<1,N> seg[N];
	int id[N],cnt[N],f[N],stk[N],top_stk,rd[N];
	vector<int> son[N];
	bool check(int x,int y){
		if(y<=1) return true;
		int epx=seg[x].search();
		return seg[y].query(epx-sam.t[x].max+sam.t[y].max,epx-1);
	}
	void dfs(int x,int pre){
		stk[++top_stk]=x;
		int left=0,right=top_stk-1;
		while(left<right){
			int mid=left+right+1>>1;
			if(check(x,stk[mid])) left=mid;
			else right=mid-1;
		}
		f[x]=f[stk[left]]+1;
		for(auto y:son[x])
			dfs(y,x);
		--top_stk;
	}
	void init(char* s){
		sam.init(); int n=strlen(s+1); id[0]=1;
		for(int i=1;i<=n;++i){
			cnt[id[i]=sam.extend(id[i-1],s[i]-'a')]++;
			seg[id[i]]=seg[id[i]].insert(i);
		}
//		for(int x=1;x<=sam.top;++x)
//			printf("[%d %d %d %d]",x,sam.t[x].s[0],sam.t[x].s[1],sam.t[x].fa);
		//bfs to get cnt 
		queue<int> q;
		for(int i=1;i<=sam.top;++i) rd[i]=0;
		for(int i=1;i<=sam.top;++i)
			if(sam.t[i].fa!=0) rd[sam.t[i].fa]++;
		for(int i=1;i<=sam.top;++i)
			if(rd[i]==0) q.push(i);
		while(!q.empty()){
			int x=q.front(); q.pop();
			int y=sam.t[x].fa;
			if(y!=0){
				son[y].push_back(x);
				cnt[y]+=cnt[x]; 
				seg[y]=seg[y].merge(seg[x]);
				--rd[y];
				if(rd[y]==0) q.push(y);
			}
		}
	}
	int solve(){
		stk[top_stk=0]=f[0]=0;
		dfs(1,0);
		int ans=0;
		for(int i=1;i<=sam.top;++i)
			ans=max(ans,f[i]);
		return ans;
	}
}exsam;
char s[N];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s+1);
	exsam.init(s);
	printf("%d\n",exsam.solve()-1);
	return 0;
}