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
bool u[7];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;cin>>n>>m;
    int c1=0,c2=0,_n=n-1,_m=m-1;
    while(_n)_n/=7,c1++;
    while(_m)_m/=7,c2++;
    c1=max(c1,1);c2=max(c2,1);
    if(c1+c2>=8)cout<<0<<endl;
    else{
        int a=1,b=1;
        rep(i,c1)a*=7;
        rep(i,c2)b*=7;
        int ans=0;
        rep(i,n)rep(j,m){
            rep(d,7)u[d]=0;
            bool ok=1;
            int _i=i,_j=j;
            rep(d,c1){
                ok=ok&&!u[_i%7];
                u[_i%7]=1;
                _i/=7;
            }
            rep(d,c2){
                ok=ok&&!u[_j%7];
                u[_j%7]=1;
                _j/=7;
            }
            // cout<<i<<' '<<j<<' '<<ok<<' '<<c1<<' '<<c2<<endl;
            ans+=ok;
        }
        cout<<ans<<endl;
    }
}