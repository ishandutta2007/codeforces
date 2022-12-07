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
    deque <char> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ops = 0;
    while(!s.empty()) {
        if((int)s.size() <= 1) break;
        if(s.front() == '(') {
            s.pop_front();
            s.pop_front();
            ops += 1;
            continue;
        }
        // Start is (
            // Keep going until next (
        int del = 1;
        while(del < (int)s.size()) {
            if(s[del] == ')') break;
            del++;
        }
        if(del == (int)s.size()) break;
        ops += 1;
        for(int i = 0; i <= del; i++) {
            s.pop_front();
        }
    }
    cout << ops << " " << (int)s.size() << endl;
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