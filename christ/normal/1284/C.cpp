#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 4e5+2;
#define all(x) (x).begin(),(x).end()
int fac[MN];
int main () {
	int n,MOD,ans=0;
	scanf ("%d %d",&n,&MOD);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = (ll)fac[i-1]*i%MOD;
	}
	for (int i = n; i >= 1; i--) {
		ans = (ans+(ll)fac[i]*(n-i+1)%MOD*fac[n-i+1]%MOD)%MOD;
	}
	printf ("%d\n",ans);
	return 0;
}