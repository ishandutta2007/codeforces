#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i) 
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db long double
using namespace std;
const int N=1e6+6; int a[N]; ll in[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n); ll ans=0;
		rep(i,1,n) scanf("%d",&a[i]),in[i]=0;
		rep(i,1,n){
			if (a[i]-1>in[i]) ans+=a[i]-1-in[i];
			rep(j,2,min(a[i],n-i)) ++in[i+j];
			if (a[i]-1<in[i]) in[i+1]+=in[i]-(a[i]-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}