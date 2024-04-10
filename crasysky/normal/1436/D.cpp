#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; 
int a[N],c[N]; ll s[N],mx[N]; vector<int> G[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,2,n){
		int p; scanf("%d",&p);
		G[p].push_back(i);
	}
	rep(i,1,n) scanf("%d",&a[i]);
	per(i,n,1){
		c[i]=!G[i].size(),s[i]=a[i];
		rep0(j,G[i].size()){
			int v=G[i][j];
			c[i]+=c[v],mx[i]=max(mx[i],mx[v]),s[i]+=s[v];
		}
		mx[i]=max(mx[i],(s[i]+c[i]-1)/c[i]);
	}
	printf("%lld\n",mx[1]); 
	return 0;
}