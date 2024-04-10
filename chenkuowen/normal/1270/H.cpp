#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
namespace IO{
	const int sz=1<<20;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return getchar();
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin)
			,p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& ret){
		ret=0; char c=gc(); int f=1;
		for(;c<'0'||c>'9';c=gc())
			if(c=='-') f=-1;
		for(;c>='0'&&c<='9';c=gc())
			ret=ret*10+(c-'0');
		ret*=f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x<0) pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush(); } }f;
}
using IO::gi;
using IO::pi;
int n,q;
struct SEG1{
	struct Node{ int key,tag; }t[MAX_N<<2];
	void up(int x){
		t[x].key=(t[x].tag>0?0:t[x+x].key+t[x+x+1].key);
	}
	void build(int p,int l,int r){
		t[p].key=r-l+1; t[p].tag=0;
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int y,int k){
		if(l==x&&r==y){
			t[p].tag+=k;
			if(t[p].tag==0){
				if(l==r) t[p].key=1;
				else up(p);
			}else t[p].key=0;
			return;
		}
		int m=l+r>>1;
		if(y<=m) change(p+p,l,m,x,y,k);
		else if(x>m) change(p+p+1,m+1,r,x,y,k);
		else change(p+p,l,m,x,m,k),change(p+p+1,m+1,r,m+1,y,k);
		up(p);
	}
	int query(){ return t[1].key; }
}seg1;
struct SEG2{
	struct Node{ int mi,mx; }t[MAX_N<<2];
	void up(int x){
		t[x].mi=min(t[x+x].mi,t[x+x+1].mi);
		t[x].mx=max(t[x+x].mx,t[x+x+1].mx);
	}
	void build(int p,int l,int r){
		t[p]=(Node){(int)1e9,-(int)1e9};
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void add(int p,int l,int r,int x,int k){	
		if(l==r){
			t[p]=(Node){k,k};
			return;
		}
		int m=l+r>>1;
		if(x<=m) add(p+p,l,m,x,k);
		else add(p+p+1,m+1,r,x,k);
		up(p);
	}
	void erase(int p,int l,int r,int x){
		if(l==r){
			t[p]=(Node){(int)1e9,-(int)1e9};
			return;
		}
		int m=l+r>>1;
		if(x<=m) erase(p+p,l,m,x);
		else erase(p+p+1,m+1,r,x);
		up(p);
	}
	int search_min(int p,int l,int r,int key){
		// find the first position which less than key or return -1
		if(l==r){
			return t[p].mi<key?l:n;
		}
		int m=l+r>>1;
		if(t[p+p].mi<key) return search_min(p+p,l,m,key);
		else return search_min(p+p+1,m+1,r,key);
	}
	int search_max(int p,int l,int r,int key){
		//find the last position which greater than key or return -1
		if(l==r)
			return t[p].mx>key?l:1;
		int m=l+r>>1;
		if(t[p+p+1].mx>key) return search_max(p+p+1,m+1,r,key);
		else return search_max(p+p,l,m,key);
	}
}seg2;
namespace SEG3{
	vector<pair<int,int> > t[MAX_N<<2];
	void change(int p,int l,int r,int x,int y,pair<int,int> k){
		if(l==x&&r==y){
			t[p].push_back(k);
			return;
		}
		int m=l+r>>1;
		if(y<=m) change(p+p,l,m,x,y,k);
		else if(x>m) change(p+p+1,m+1,r,x,y,k);
		else change(p+p,l,m,x,m,k),change(p+p+1,m+1,r,m+1,y,k);
	}
	void solve(int p,int l,int r){
		vector<pair<int,int> > s;
		for(auto x:t[p]){
		//	if(l<=3&&3<=r) printf("<%d %d>\n",x.first,x.second);
			int pos1=seg2.search_min(1,1,n,x.second);
			int pos2=seg2.search_max(1,1,n,x.second);
			if(pos1>x.first)
				s.push_back(make_pair(x.first+1,min(pos1,pos2)));
			if(pos2<x.first)
				s.push_back(make_pair(max(pos1,pos2)+1,x.first));
			seg2.add(1,1,n,x.first,x.second);
		}
		for(auto x:s){
			if(x.first<=x.second){
				seg1.change(1,1,n,x.first,x.second,1);
		//		if(l<=3&&3<=r) printf("|%d %d|\n",x.first,x.second);
			}
		}
		if(l==r){
			pi(seg1.query());
	//		exit(0);
		}
		else{
			int m=l+r>>1;
			solve(p+p,l,m);
			solve(p+p+1,m+1,r);
		}
		for(auto x:s){
			if(x.first<=x.second)
				seg1.change(1,1,n,x.first,x.second,-1);
		}
		for(auto x:t[p])
			seg2.erase(1,1,n,x.first);
	}
}
pair<int,int> a[MAX_N];
int main(){
	gi(n); gi(q);
	for(int i=1;i<=n;++i){
		a[i].first=1;
		scanf("%d",&a[i].second);
	}
	seg1.build(1,1,n);
	seg2.build(1,1,n);
	for(int i=1;i<=q;++i){
		pair<int,int> k; scanf("%d%d",&k.first,&k.second);
		if(a[k.first].first<i){
			SEG3::change(1,1,q,a[k.first].first,i-1
				,make_pair(k.first,a[k.first].second));
//			printf("[%d %d %d %d]\n",a[k.first].first,i-1
//				,k.first,a[k.first].second);
		}
		a[k.first]=make_pair(i,k.second);
	}
	for(int i=1;i<=n;++i){
		if(a[i].first<=q){
			SEG3::change(1,1,q,a[i].first,q,make_pair(i,a[i].second));
//			printf("[%d %d %d %d]\n",a[i].first,q,i,a[i].second);
		}
	}
	SEG3::solve(1,1,q);
	return 0;
}