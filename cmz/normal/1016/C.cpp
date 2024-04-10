#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+100;
int n,a[maxn],b[maxn];
ll Now,Fir[maxn],Sec[maxn],Sum1[maxn],Sum2[maxn],Ans,P1[maxn],P2[maxn];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%lld",&b[i]);
	for(int i=n; i>=1; --i)P1[i]=P1[i+1]+a[i],P2[i]=P2[i+1]+b[i]; Now=0;
	for(int i=n; i>=1; --i)Fir[i]=Fir[i+1]+Now,Now+=a[i]; Now=0;
	for(int i=n; i>=1; --i)Sec[i]=Sec[i+1]+Now,Now+=b[i];
	for(int i=n; i>=1; --i)Sum1[i]=Sum1[i+1]+1ll*(n-i)*a[i];
	for(int i=n; i>=1; --i)Sum2[i]=Sum2[i+1]+1ll*(n-i)*b[i];
	Now=0;
	for(int i=1,T=0; i<=n; ++i)
		if(i&1) {
			Ans=max(Ans,Now+Fir[i]+Sum2[i]+1ll*T*P1[i]+1ll*(T+n-i+1)*P2[i]);
			Now+=1ll*T*a[i];
			++T;
			Ans=max(Ans,Now+Sec[i]+Sum1[i+1]+1ll*T*P2[i]+1ll*(T+n-i+1)*P1[i+1]);
			Now+=1ll*T*b[i];
			++T;
		} else {
			Ans=max(Ans,Now+Sec[i]+Sum1[i]+1ll*T*P2[i]+1ll*(T+n-i+1)*P1[i]);
			Now+=1ll*T*b[i];
			++T;
			Ans=max(Ans,Now+Fir[i]+Sum2[i+1]+1ll*T*P1[i]+1ll*(T+n-i+1)*P2[i+1]);
			Now+=1ll*T*a[i];
			++T;
		}
	printf("%lld",Ans);
	return 0;
}