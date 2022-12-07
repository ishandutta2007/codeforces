#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

#define vector deque
#define pi pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    vector <pi> ans;
    vector <int> s;
    while(!v.empty()) {
        int ind = 0;
        for(int i = 1; i < (int)v.size(); i++) {
            if(v[i] == v[0]) {
                ind = i;
                break;
            }
        }
        if(ind == 0) {
            cout << -1 << endl;
            return;
        }
        vector <int> w;
        s.push_back(ind * 2);
        for(int i = ind - 1; i >= 1; i--) {
            w.push_back(v[i]);
        }
        for(int i = 1; i < ind; i++) {
            ans.push_back({cnt + ind + i, v[i]});
        }
        for(int i = ind + 1; i < (int)v.size(); i++) {
            w.push_back(v[i]);
        }
        v = w;
        cnt += 2*ind;
    }
    cout << (int)ans.size() << endl;
    for(auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
    cout << (int)s.size() << endl;
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}