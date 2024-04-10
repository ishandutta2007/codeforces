#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
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
    int t; cin >> t;
    while(t--) {
        ll n, a, b; cin >> n >> a >> b;
        ll sc = a+b;
        ll hightie = min(n, sc-1);
        ll lowtie = sc-hightie;
        ll possibletie = hightie-lowtie+1;
        ll worst = min(n, possibletie+lowtie-1);
        ll best;
        if(sc == n+n) best = n;
        else {
            sc++;
            hightie = min(n, sc-1);
            best = sc-hightie;
        }
        cout << best << ' ' << worst << endl;
    }
}