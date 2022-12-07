#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

char s[MAXN];
int arr[MAXN][3][3];
int n, m;
int q[MAXN][2];

void pre() {
    forn(i, 3) forn(j, 3) arr[0][i][j] = 0;
    for(int i=1; i<=n; i++) {
        int k;
        if(s[i]=='a') k = 0;
        else if(s[i]=='b') k = 1;
        else k = 2;
        int j = i%3;
        // arr[i][j][k] needs to be updated. All else will stay the same.
        forn(a, 3) forn(b, 3) arr[i][a][b] = arr[i-1][a][b];
        arr[i][j][k] += 1; 
    }
}

void post(int k) {
    // Solving query k.
    int temp[3][3];
    int sum_temp = 0;
    forn(i, 3) {
        forn(j, 3) {
            temp[i][j] = arr[q[k][1]][i][j] - arr[q[k][0] - 1][i][j];
            sum_temp += temp[i][j];
        }
    }
    // Now try 6 possibilities.
    int ans = MOD;
    forn(a, 3) {
        forn(b, 3) {
            forn(c, 3) {
                if(a!=b && b!=c && c!=a) {
                    // Send temp[0] to a, temp[1] to b, temp[2] to c.
                    int z = sum_temp - temp[0][a] - temp[1][b] - temp[2][c];
                    ans = min(ans, z);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n >> m;
    s[0] = '0';
    forn(i, n) cin >> s[i+1];
    pre();
    forn(i, m) {
        cin >> q[i][0] >> q[i][1];
        post(i);
    }
    return 0;
}