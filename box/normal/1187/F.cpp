// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int qpow(int b, int e) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b % MOD;
		b = 1ll * b * b % MOD;
		e >>= 1;
	}
	return ans;
}

int l[200005],r[200005];
int D[200005],C[200005];
int P[200005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    rep1(i,n)cin>>l[i];
    rep1(i,n)cin>>r[i];
    rep1(i,n)D[i]=qpow(r[i]-l[i]+1,MOD-2);
    rep1(i,n){
        int a=max(l[i],l[i-1]),b=min(r[i],r[i-1]);
        if(a>b)continue;
        P[i]=1ll*(b-a+1)*D[i-1]%MOD*D[i]%MOD;
        if(i-1){
            a=max(a,l[i-2]),b=min(b,r[i-2]);
            if(a>b)continue;
            C[i]=1ll*(b-a+1)*D[i-2]%MOD*D[i-1]%MOD*D[i]%MOD;
        }
    }
    // rep1(i,n)cout<<P[i]<<' '<<C[i]<<endl;
    int ans=1ll*n*n%MOD;
    rep1(i,n)ans=(ans+1ll*(MOD-2*n)*P[i])%MOD;
    int s=0;
    rep1(i,n)s=(s+P[i])%MOD;
    ans=(ans+1ll*s*s)%MOD;
    rep1(i,n)ans=(ans+1ll*(MOD-P[i])*P[i]+P[i])%MOD;
    rep1(i,n-1)ans=(ans+2*(1ll*(MOD-P[i])*P[i+1]+C[i+1]))%MOD;
    cout<<ans<<endl;
}