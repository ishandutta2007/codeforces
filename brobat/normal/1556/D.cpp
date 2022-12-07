#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 10010
#define MOD 1000000007
 
int n, ans, t;
int arr[MAXN][33];
map <int, int> andd;
map <int, int> orr;
 
int find(unsigned int x, unsigned int k) {
    return ((x & (1 << (k - 1))) >> (k - 1));
}
 
void AND(int x, int y) {
    cout << "and " << x << " " << y << endl;
    cin >> t;
    andd[x] = t;
    forn(k, 1, 33) {
        int b = find(t, k);
        if(b==1) {
            arr[x][k] = 1;
            arr[y][k] = 1;
        }
        else {
            if(arr[x][k] == 1) arr[y][k] = 0;
            if(arr[y][k] == 1) arr[x][k] = 0;
        }
    }
}
 
void OR(int x, int y) {
    cout << "or " << x << " " << y << endl;
    cin >> t;
    orr[x] = t;
    forn(k, 1, 33) {
        int b = find(t, k);
        if(b==0) {
            arr[x][k] = 0;
            arr[y][k] = 0;
        }
        else {
            if(arr[x][k] == 0) arr[y][k] = 1;
            if(arr[y][k] == 0) arr[x][k] = 1;
        }
    }
}
 
void checkAND(int x, int y) {
    t = andd[x];
    forn(k, 1, 33) {
        int b = find(t, k);
        if(b==1) {
            arr[x][k] = 1;
            arr[y][k] = 1;
        }
        else {
            if(arr[x][k] == 1) arr[y][k] = 0;
            if(arr[y][k] == 1) arr[x][k] = 0;
        }
    }
}
 
void checkOR(int x, int y) {
    t = orr[x];
    forn(k, 1, 33) {
        int b = find(t, k);
        if(b==0) {
            arr[x][k] = 0;
            arr[y][k] = 0;
        }
        else {
            if(arr[x][k] == 0) arr[y][k] = 1;
            if(arr[y][k] == 0) arr[x][k] = 1;
        }
    }
}
 
void solve() {
    cin >> n >> ans;
    forn(i, 0, n+1) forn(j, 1, 33) arr[i][j] = -1;
    // How to find AND and OR values.
    forn(i, 1, n+1) {
        if(i==n) {
            OR(n, 1);
            AND(n, 1);
        }
        else {
            OR(i, i+1);
            AND(i, i + 1);
        }
    }
    forn(i, 1, n+1) {
        if(i==n) {
            checkOR(n, 1);
            checkAND(n, 1);
        }
        else {
            checkOR(i, i + 1);
            checkAND(i, i + 1);
        }
    }
    // forn(i, 1, n+1) forn(j, 1, 33) if(arr[i][j] == -1) cout << "F"; 
    vector <int> v(n);
    forn(i, 0, n) v[i] = 0;
    forn(i, 1, n+1) {
        forn(j, 1, 33) {
            if(arr[i][j]==1) v[i-1] += (1<<(j-1));
        }
    }
    // for(auto i : v) cout << i << " ";
    sort(v.begin(), v.end());
    cout << "finish " << v[ans - 1] << endl;
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();
 
    return 0;
}