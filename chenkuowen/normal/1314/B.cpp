#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1<<17|5,INF=1e9;
int a[MAX_N];
void dmax(int& x,int y){ x=max(x,y); }
int add(int x,int y){
	if(x==-INF||y==-INF) return -INF;
	return x+y;
}
int cnt(int x){
	int ret=0;
	while(x) x-=x&-x,++ret;
	return ret;
}
void solve1(int x1,int x2,int y2,int key,vector<int>& g){
	dmax(g[x1|((x2|y2)<<1)],key+(x2|y2));
}
void solve(int x1,int x2,int y1,int y2,int key,vector<int>& g){
	key+=(x1|y1)+(x2|y2);
	solve1(x1,y1,x2,key,g);
	solve1(x1,y1,y2,key,g);
	solve1(y1,x1,x2,key,g);
	solve1(y1,x1,y2,key,g);
}
vector<int> solve(int l,int r){
	vector<int> ret; ret.resize(4);
	if(r-l+1==2){
		if(a[l]+a[r]==0) ret[0]=0;
		else ret[0]=-INF;
		if(a[l]+a[r]==1) ret[1]=ret[2]=1;
		else ret[1]=ret[2]=-INF;
		if(a[l]+a[r]==2) ret[3]=1;
		else ret[3]=-INF;
		return ret;
	}
	int m=l+r>>1; 
	vector<int> f1=solve(l,m),f2=solve(m+1,r);
	for(int i=0;i<4;++i) ret[i]=-INF;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(f1[i]!=-INF&&f2[j]!=-INF)
				solve(i&1,(i>>1)&1,j&1,(j>>1)&1,f1[i]+f2[j],ret);
//	printf("[%d %d]",l,r);
//	for(auto x:ret) printf("{%d}",x);
//	puts("");
	return ret;
}
int main(){
	int n,k; scanf("%d%d",&n,&k);
	n=1<<n;
	for(int i=1;i<=k;++i){
		int x; scanf("%d",&x);
		a[x]=1;
	}
	vector<int> ret=solve(1,n);
	int ans=-INF;
	for(int i=0;i<ret.size();++i)
		ans=max(ans,ret[i]+(i>0));
	printf("%d\n",ans);
	return 0;
}