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

ll va[256];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; ll t; cin >> n >> t;
    string s; cin >> s;
    int c = 1;
    iter(i, 'a', 'z'+1) {
        va[i] = c;
        c = 2 * c;
    }
    t = t - (va[s[n-1]] - va[s[n-2]]);
    s.pop_back(); s.pop_back();
    sort(all(s));
    reverse(all(s));
    for(char c:s){
        if(t<0)t+=va[c];
        else t-=va[c];
    }
    if(t==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}