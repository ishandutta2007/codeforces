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
const int MOD = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, k; cin>>n>>k;
    int th=n-k+1;
    int pr=0;
    ll ans=0;
    int cnt=1;
    rep1(i,n){
        int v;cin>>v;
        if(v>=th){
            ans+=v;
            if(pr){
                cnt=1ll*cnt*(i-pr)%MOD;
            }
            pr=i;
        }
    }
    cout<<ans<<' '<<cnt<<endl;
}