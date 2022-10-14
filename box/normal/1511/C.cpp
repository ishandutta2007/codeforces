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

int be[55];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    rep1(i,n){
        int c;cin>>c;
        if(!be[c])be[c]=i;
    }
    rep(i,q){
        int c;cin>>c;
        int p=be[c];
        cout<<p<<" \n"[i==q-1];
        rep1(j,50)if(be[j]<p)be[j]++;
        be[c]=1;
    }
}