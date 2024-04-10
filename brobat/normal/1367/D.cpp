#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    string s; cin >> s;
    int n; cin >> n;
    vector <int> arr(n);
    forn(i, 0, n) cin >> arr[i];
    vector <int> o(n, -1); // Stores indexes of letters.
    vector <int> v; // Stores values for sum function.
    vector <int> new_occ;
    map<int, bool> done;
    forn(a, 0, 26) {
        vector <int> temp;
        forn(b, 0, n) {
            if(done[b]) continue;
            int x = 0;
            for(auto i : v) {
                x += abs(i - b);
            }
            if(x==arr[b]) {
                temp.push_back(b);
                o[b] = a;
                done[b] = true;
            }
        }
        for(auto i : temp) {
            v.push_back(i);
        }
        if(temp.size() > 0) new_occ.push_back(temp.size());
    }
    // forn(i, 0, n) cout << o[i] << " ";
    vector <int> occ(26, 0);
    forn(i, 0, s.length()) occ[s[i] - 'a']++;
    reverse(new_occ.begin(), new_occ.end());
    // for(auto i : new_occ) cout << i << " ";
    vector <char> c(n);
    {
        int a = 0, b = 0;
        while(a < new_occ.size() && b < occ.size()) {
            if(new_occ[a]<=occ[b]) {
                forn(i, 0, n) {
                    if(o[i]==new_occ.size() - a - 1) {
                        c[i] = 'a' + b;
                    }
                }
                a++;
            }
            b++;
        }
    }
    for(auto i : c) cout << i;
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}