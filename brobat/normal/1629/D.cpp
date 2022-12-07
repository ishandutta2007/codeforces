#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    map<string, int> m; // first occurence of m
    map<string, int> rev; // last occurence of rev
    // 1 indexed
    bool pos = false;
    forn(i, 0, n) {
        string temp;
        cin >> temp;
        if(!pos && temp.length() == 1) {
            cout << "YES" << endl;
            pos = true;
        }
        if(m[temp] == 0) {
            m[temp] = i + 1;
        }
        reverse(temp.begin(), temp.end());
        rev[temp] = i + 1;
    }
    if(pos) return;
    for(auto i : m) {
        string temp = i.first;
        // reverse(temp.begin(), temp.end());
        if(rev[temp] >= i.second) {
            cout << "YES" << endl;
            return;
        }
    }
    // cout << "F" << endl;
    // Check for 2 + 3
    for(auto i : rev) {
        if(i.first.length() != 3) continue;
        string temp = "";
        temp += i.first[0];
        temp += i.first[1];
        if(m[temp] > 0 && m[temp] < i.second) {
            cout << "YES" << endl;
            return;
        }
    }
    // Check for 3 + 2
    for(auto i : m) {
        if(i.first.length() != 3) continue;
        string temp = "";
        temp += i.first[0];
        temp += i.first[1];
        if(rev[temp] > i.second) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}