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

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k;cin>>n>>k;
    if(k==1)cout<<0<<endl;
    else {
        ll a=1,b=k-1;
        if(b>n){
            a+=b-n;
            b=n;
        }
        if(a>n)cout<<0<<endl;
        else cout<<(k/2)-a+(k%2)<<endl;
    }
}