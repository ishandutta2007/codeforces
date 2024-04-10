#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,t,a[100005],mx;
long long s,ss;
int main(){
	scanf("%d",&t);
	while(t--){
		s=ss=mx=0;
		scanf("%d",&n);
		rep(i,n){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		sort(a+1,a+n+1);
		rep(i,n) s+=a[i];
		rep(i,n){
			s-=a[i];
			ss+=s-1ll*a[i]*(n-i);
		}
		printf("%lld\n",mx-ss);
	}
	return 0;
}