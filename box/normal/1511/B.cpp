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
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        int v=1;rep(i,c-1)v*=10;
        int g=1;rep(i,b-c)g=g*10+1;
        int x=1;rep(i,a-1)x*=10;
        cout<<x<<' '<<g*v<<'\n';
    }
}