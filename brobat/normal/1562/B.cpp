#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n;
vector <int> v;
char temp;

// arr = [1, 4, 6, 8, 9, 22, 32, 52, 72, 25, 35, 55, 75, 33, 77, 27, 57]

void solve() {
    int n;
    vector <int> v;
    char temp;
    cin >> n;
    forn(i, 0, n) {
        cin >> temp;
        v.push_back(temp - '0');
    }
    // Store first and last occurence of each digit.
    int first[11];
    int last[11];
    forn(i, 0, 10) {
        first[i+1] = last[i+1] = -1;
    }
    forn(i, 0, n) {
        if(first[v[i]] == -1) {
            first[v[i]] = i;
            last[v[i]] = i;
        }
        else {
            last[v[i]] = i;
        }
    }
    int x[5] = {1, 4, 6, 8, 9};
    forn(i, 0, 5) {
        if(first[x[i]] != -1) {
            cout << 1 << endl;
            cout << x[i] << endl;
            return;
        }
    }
    // arr = [1, 4, 6, 8, 9, 22, 32, 52, 72, 25, 35, 55, 75, 33, 77, 27, 57]
    cout << 2 << endl;
    int y[4] = {2, 3, 5, 7};
    forn(i, 0, 4) {
        forn(j, 0, 4) {
            if(first[y[i]] != -1 && last[y[j]] != -1 && first[y[i]] < last[y[j]]) {
                int z = 10*y[i] + y[j];
                if(z==23 || z==53 || z==37 || z==73) continue;
                cout << y[i] << y[j] << endl;
                return;
            }
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // pre();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}