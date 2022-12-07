#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void print(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
}

pair<int, int> solve(vector <int> &a, vector <int> &b) {
    int t;
    print(a[0], a[1], b[0]);
    cin >> t;
    if(t == 1) {
        // b[0] is crewmate
        print(a[0], b[0], a[2]);
        cin >> t;
        if(t == 1) {
            // a[0] is crewmate, a[1] is imposter, a[2] is imposter.
            return {b[0], a[1]};
        }
        else {
            // a[0] is imposter, a[2] is imposter.
            return {b[0], a[0]};
        }
    }   
    print(a[0], a[1], b[1]);
    cin >> t;
    if(t == 1) {
        // b[1] is crewmate
        print(a[0], b[1], a[2]);
        cin >> t;
        if(t == 1) {
            // a[0] is crewmate, a[1] is imposter, a[2] is imposter.
            return {b[1], a[1]};
        }
        else {
            // a[0] is imposter, a[2] is imposter.
            return {b[1], a[0]};
        }
    }
    print(a[0], a[1], b[2]);
    cin >> t;
    if(t == 0) {
        // a[0] and a[1] are imposters.
        print(b[0], b[1], a[0]);
        cin >> t;
        if(t == 1) {
            // b[0] and b[1] are crewmates.
            return {b[0], a[0]};
        }
        else {
            // One of b[0], b[1] is imposter. b[2] is crewmate.
            return {b[2], a[0]};
        }
    }
    // b[0], b[1], b[2] are all crewmates.
    print(a[0], a[2], b[0]);
    cin >> t;
    if(t == 1) {
        // a[0] is crewmate. 
        return {b[0], a[1]};
    }
    else {
        // a[1] is crewmate.
        return {b[0], a[0]};
    }
}

void solve() {
    int n;
    cin >> n;
    int f1 = -1, f2 = -1;
    // f1 --> More imposters.
    // f2 --> More crewmates.
    for(int i = 1; i < n; i += 3) {
        print(i, i + 1, i + 2);
        int t; cin >> t;
        if(t == 0) {
            f1 = i;
        }
        if(t == 1) {
            f2 = i;
        }
        if(f1 > 0 && f2 > 0) break;
    }
    vector <int> a = {f1, f1 + 1, f1 + 2}; // Contains 2 or more imposters.
    vector <int> b = {f2, f2 + 1, f2 + 2}; // Contains 2 or more crewmates.
    pair <int, int> ci = solve(a, b);
    vector <int> imp(n + 1, -1); // 0 if crewmate, 1 if imposter.
    imp[ci.first] = 0;
    imp[ci.second] = 1;
    for(int i = 1; i <= n; i++) {
        if(imp[i] == -1) {
            print(ci.first, ci.second, i);
            int t; cin >> t;
            if(t == 1) imp[i] = 0;
            else imp[i] = 1;
        }
    }
    int xx = 0;
    forn(i, 0, n + 1) {
        if(imp[i] == 1) {
            xx++;
        }
    }
    cout << "! " << xx << " ";
    forn(i, 0, n + 1) {
        if(imp[i] == 1) {
            cout << i << " ";
        }
    }
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