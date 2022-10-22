#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
struct DSF{
	int fa[MAX_N],r[MAX_N];
	void ms(int x){ fa[x]=x,r[x]=0; }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	bool mb(int x,int y){ return fs(x)==fs(y); }
	void merge(int x,int y){
		x=fs(x),y=fs(y);
		if(r[x]<r[y]) swap(x,y);
		fa[y]=x; r[x]=max(r[x],r[y]+1);
	}
}dsf;
struct E{ int x,y,key,mark,id; };
vector<E> e;
bool cmp(E x,E y){
	return x.key<y.key||x.key==y.key&&x.mark<y.mark; 
}
bool cmp2(E x,E y){
	return x.key<y.key||x.key==y.key&&x.mark>y.mark;
}
pair<int,int> check(int std,int n){ 
	//get the mininum number of capital roads
	for(int i=1;i<=n;++i) dsf.ms(i);
	for(int i=0;i<e.size();++i)
		if(e[i].mark) e[i].key+=std;
	sort(e.begin(),e.end(),cmp);
	int ans=0,cnt=0;
	for(int i=0;i<e.size();++i)
		if(!dsf.mb(e[i].x,e[i].y)){
			dsf.merge(e[i].x,e[i].y);
			if(e[i].mark) ++cnt;
			ans+=e[i].key; 
		}
	for(int i=0;i<e.size();++i)
		if(e[i].mark) e[i].key-=std;
	return make_pair(ans,cnt);
}
int check2(int n,int k,int m){
	for(int i=1;i<=n;++i) dsf.ms(i);
	for(int i=0;i<e.size();++i)
		if(e[i].mark&&m>0){
			e[i].mark=-1;
			--m;
		}
	sort(e.begin(),e.end(),cmp);
	int cnt=0;
	vector<int> ans;
	for(int i=0;i<e.size();++i)
		if(!dsf.mb(e[i].x,e[i].y)){
			dsf.merge(e[i].x,e[i].y);
			if(e[i].mark) ++cnt;
			ans.push_back(e[i].id);
		}
	for(int i=1;i<=n;++i)
		if(!dsf.mb(1,i)){
			puts("-1");
			exit(0);
		}
	if(cnt==k){
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d ",x);
		exit(0);
	}
	for(int i=0;i<e.size();++i)
		if(e[i].mark==-1) e[i].mark=1;
	return cnt;
}
void solve(int std,int n,int k){
	int m=0;
	for(int i=0;i<e.size();++i){
		if(e[i].mark){
			e[i].key+=std;
			++m;
		}
	}
	int left=0,right=m;
	while(left<=right){
		int mid=left+right>>1;
		if(check2(n,k,mid)>k) right=mid-1;
		else left=mid+1;
	}
	puts("-1");
	exit(0);
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	e.resize(m);
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].key);
		e[i].mark=e[i].x==1||e[i].y==1;
		e[i].id=i+1;
	}
	int left=-1e5,right=1e5;
	while(left<right){
		int mid=left+right>>1;
		if(check(mid,n).second>k) left=mid+1;
		else right=mid;
	}
	solve(right,n,k);
	return 0;
}