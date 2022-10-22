#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int a[N],f[25][N],n;
struct OP{
	int cnt[N],l,r,ans=0;
	void clear(){ l=1,r=0,ans=0; }
	void add(int x,int k){
		ans-=max(cnt[x]-1,0);
		cnt[x]+=k;
		ans+=max(cnt[x]-1,0);
	}
}op;
void solve(int f[],int g[],int k){
	int p=0;
	for(int i=1;i<=n;++i){
		op.add(a[i],1);
		while(op.ans>k) ++p,op.add(a[p],-1);
		f[i]=min(f[i],g[p]+1);
	}
	for(int i=p+1;i<=n;++i) op.add(a[i],-1);
}
bool perfect_square(int x){
	int y=sqrt(x+1e-8);
	while((y+1)*(y+1)<=x) ++y;
	while(y*y>x) --y;
	return y*y==x;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int k; scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i){
			int x; scanf("%d",&x); a[i]=1;
			for(int j=2;j*j*j<=x;++j){
				int cnt=0;
				while(x%j==0) x/=j,cnt^=1;
				if(cnt) a[i]*=j;
			}
			if(!perfect_square(x)) a[i]*=x;
		}
		vector<pair<int,int> > b(n);
		for(int i=1;i<=n;++i) b[i-1]=make_pair(a[i],i);
		sort(b.begin(),b.end());
		int m=1;
		for(int i=0;i<n;++i){
			if(i>0&&b[i].first!=b[i-1].first) ++m;
			a[b[i].second]=m;
		}
		for(int t=0;t<=k;++t)
			for(int i=1;i<=n;++i)
				f[t][i]=(int)1e9;
		for(int t=0;t<=k;++t)
			for(int u=0;u<=t;++u)
				solve(f[t],f[u],t-u);
		printf("%d\n",f[k][n]);
	}
	return 0;
}