#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector <int> v;
    map<int, int> m;
    forn(i, 0, n*n) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        m[temp]++;
    }
    int o = 0;
    int t = 0;
    int f = 0;
    for(auto i : m) {
        if(i.second % 4 == 0) f++;
        else if(i.second % 2 == 0) t++;
        else o++;
    }
    int ans[n][n];
    if(n%2==0) {
        // even
        if(o||t) {
            cout << "NO";
            return;
        }
        cout << "YES\n";
        vector<int> v;
        for(auto i : m) {
            while(i.second != 0) {
                v.push_back(i.first);
                i.second--;
                m[i.first]--;
            }
        }
        int k = 0;
        forn(i, 0, n/2) {
            forn(j, 0, n/2) {
                ans[i][j] = ans[n-i-1][j] = ans[i][n-j-1] = ans[n-i-1][n-j-1] = v[k];
                k += 4;
            }
        }
        forn(i, 0, n) {
            forn(j, 0, n) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }     
    }
    else {
        // odd
        if(o>1||t>(n-1)) {
            cout << "NO";
            return;
        }
        cout << "YES\n";
        for(auto i : m) {
            if(i.second%4 == 1 || i.second%4==3) {
                ans[n/2][n/2] = i.first;
                m[i.first]--;
                break;
            }
        }
        vector <int> v;
        for(auto i : m) {
            int z = (i.second/4)*4;
            forn(j, 0, z) {
                v.push_back(i.first);
            }
            m[i.first] -= z;
        }
        for(auto i : m) {
            if(i.second == 2) {
                v.push_back(i.first);
                v.push_back(i.first);
                i.second = 0;
                m[i.first] = 0;
            }
        }
        int k = 0;
        forn(i, 0, n/2) {
            forn(j, 0, n/2) {
                ans[i][j] = ans[n-i-1][j] = ans[i][n-j-1] = ans[n-i-1][n-j-1] = v[k];
                k += 4;
            }
        }
        forn(i, 0, n/2) {
            ans[i][n/2] = ans[n-i-1][n/2] = v[k];
            ans[n/2][i] = ans[n/2][n-i-1] = v[k+2];
            k += 4;
        }
        forn(i, 0, n) {
            forn(j, 0, n) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}