#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc,n,m,q,a[200005];
vector<int>pri;
ll f[1000000],*g[100];
void getpri(int x){
	pri.clear();int X=x;
	for(int i=2;i*i<=X;i++)if(X%i==0){
		pri.push_back(i);
		while(X%i==0)X/=i;
	}
	if(X>1)pri.push_back(X);
}
multiset<ll>mst;
void sol(){
	scanf("%d%d",&n,&q);getpri(n);mst.clear();
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	ll *it=f;int cnt=0;m=pri.size();
	for(int i=0;i<m;i++)g[i]=it,it+=n/pri[i],cnt+=n/pri[i];
	memset(f,0,(cnt+2)<<4);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			g[j][i%(n/pri[j])]+=a[i];
	for(int i=0;i<m;i++)
		for(int j=0;j<n/pri[i];j++)
			mst.insert(g[i][j]*(n/pri[i]));
	printf("%lld\n",*mst.rbegin());
	while(q--){
		int p,v;scanf("%d%d",&p,&v);p--;
		for(int i=0;i<m;i++){
			int z=p%(n/pri[i]);
			mst.erase(mst.lower_bound(g[i][z]*(n/pri[i])));
			g[i][z]-=a[p],g[i][z]+=v;
			mst.insert(g[i][z]*(n/pri[i]));
		}
		a[p]=v;
		printf("%lld\n",*mst.rbegin());
	}
}
int main(){
	scanf("%d",&tc);
	while(tc--)sol();
}