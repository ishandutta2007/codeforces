#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char arr[n][n];
    int num_2 = 0;
    forn(i, 0, n) if(s[i]=='2') num_2++;
    if(num_2==1 || num_2==2) {
        cout << "NO" << endl;
        return;
    }
    forn(i, 0, n) forn(j, 0, n) {
        if(i==j) arr[i][j] = 'X';
        else arr[i][j] = '=';
    }
    if(num_2) {
        vector <int> v;
        forn(i, 0, n) if(s[i]=='2') v.push_back(i);
        v.push_back(v[0]);
        forn(i, 0, v.size() - 1) {
            arr[v[i]][v[i+1]] = '+';
            arr[v[i+1]][v[i]] = '-';
        }
    }
    cout << "YES" << endl;
    forn(i, 0, n) {
        forn(j, 0, n) cout << arr[i][j];
        cout << endl;
    }
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