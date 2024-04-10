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

int cray[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        string s; cin >> s;
        cray[0] = 0;
        int l = 1,r = -1;
        int pt = 0;
        while(pt != s.length()) {
            if(s[pt] == '<') { 
                int cat = pt;
                while(s[pt] == '<') pt++;
                pt--;
                int terms = pt - cat + 1;
                r -= terms;
                cray[cat] -= terms;
                int st = r+1;
                while(cat != pt+1) {
                    cray[cat+1] = cray[cat]+1;
                    cat++;
                }
            }
            else { cray[pt+1] = r; r--; }
            pt++;
        }
        int mi = 0;
        rep(i, n) mi = min(mi, cray[i]);
        rep(i, n) {
            if(i) cout << ' ';
            cout << cray[i] - mi + 1;
        }
        cout << endl;
        l = 1, r = -1;
        pt = 0;
        cray[0] = 0;
        while(pt != s.length()) {
            if(s[pt] == '<') { cray[pt+1] = l; l++; }
            else { cray[pt+1] = r; r--; }
            pt++;
        }
        mi = 0;
        rep(i, n) mi = min(mi, cray[i]);
        rep(i, n) {
            if(i) cout << ' ';
            cout << cray[i] - mi + 1;
        }
        cout << endl;
    }
}