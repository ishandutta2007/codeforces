// writer: w33z8kqrqk8zzzx33
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

list<char> c;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l; cin >> l;
    rep(i, l) {
        char v;  cin >> v;
        c.push_back(v);
    }
    for(char re='z'; re>'a'; re--) {
        auto at = c.begin();
        char targ = re-1;
        while(at != c.end()) {
            if(*at != re) {
                ++at;
                continue;
            }
            bool rem = 0;
            if(at != c.begin()) {
                auto opt = at; --opt;
                if(targ == *opt) rem = 1;
            }
            if(at != (--c.end())) {
                auto opt = at; ++opt;
                if(targ == *opt) rem = 1;
            }
            if(rem) {
                auto k = at;
                ++at;
                c.erase(k);
            } else ++at;
        }
        at = --c.end();
        while(at != --c.begin()) {
            if(*at != re) {
                --at;
                continue;
            }
            bool rem = 0;
            if(at != c.begin()) {
                auto opt = at; --opt;
                if(targ == *opt) rem = 1;
            }
            if(at != (--c.end())) {
                auto opt = at; ++opt;
                if(targ == *opt) rem = 1;
            }
            if(rem) {
                auto k = at;
                --at;
                c.erase(k);
            } else --at;
        }
    }
    cout << l - c.size() << endl;
}