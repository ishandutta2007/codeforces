#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=2e5+5,P=998244353;
int a[N]; ll s1[N],s2[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		ll s=0;
		rep(i,1,n) scanf("%d",&a[i]),s+=a[i];
		rep(i,1,n) s1[i]=s1[i-1]+a[i];
		rep(i,1,n) s2[i]=(i>=2?s2[i-2]:0)+a[i];
		ll ans=0;
		#define ok(v) ((v)<s-(v))
		rep(i,0,n) if (ok(s1[i])) ++ans;
		rep(i,2,n) if (ok(s-s1[i-1])) ++ans;
		rep(u,0,1)
			rep(v,0,1){
				int t=u==0?1:2;
				rep(l,t,n-1){
					int z=u==0&&v==1?2:1;
					int p=z,q=(n+v-l)/2;
					//[l,l+2*k-1] ?0000[01010101]11111?
					//v==1:l+2*k-1<=n v==0:l+2*k-1<=n-1
					while (p<=q){
						int m=p+q>>1;
						if (ok(s2[l+2*m-2]-s2[max(0,l-2)]+s1[l-1]-u*a[1]+(v==0)*a[n])) p=m+1;
						else q=m-1;
					}
					ans+=p-z;
				}
			}
		printf("%d\n",ans%P);
	}
	return 0;
}