#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i, f, g;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int f = 0; f < m; ++f) {
            char ch;
            cin >> ws >> ch;
            if (ch != 'W' and ch != 'B' and ch != 'G') {
                cout << "#Color";
                return 0;
            }
        }
    }

    cout << "#Black&White";


    return 0;
}