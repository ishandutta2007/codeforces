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

vector<pii>ree;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    rep(i,n){
        int x,v;cin>>x>>v;
        ree.push_back({x+v,x-v});
    }
    sort(all(ree));
    int cl=-2e9,a=0;
    rep(i,n)if(cl<=ree[i].se)cl=ree[i].fi,a++;
    cout<<a<<endl;
}