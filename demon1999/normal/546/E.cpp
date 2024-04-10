#include  <iostream>
#include  <cstdio>
#include  <fstream>
#include  <algorithm>
#include  <set>
#include  <map>
#include  <string>
#include  <cstring>
#include  <vector>
#include  <deque>
#include  <cmath>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef long double ld;
int f[300][300], c[301][300], use[300], a, n, m, sum, sum1, b, ans, cc;
bool dfs(int nu, int k) {
    // << nu << " " << k << endl;
    use[nu] = 1;
    if (nu == 2 * n + 1) {
        cc = k; ans += cc;
        return true;
    }
    for (int i = 0; i < 2 * n + 2; i++) {
        if( use[i] == 0 && (c[nu][i] + f[nu][i] > 0 && dfs(i, min(k, c[nu][i] + f[nu][i])))) {
            f[i][nu] += cc;
            f[nu][i] = -f[i][nu];
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    forn (i, n) {
            cin >> a;
            c[0][i + 1] = a;
            sum += a;
    }
    forn (i, n) {
            cin >> a;
            c[i + 1][i + n + 1] = 200;
            sum1 += a;
            c[i + n + 1][2 * n + 1] = a;
    }
    if (sum1 != sum) {
        cout << "NO";
        return 0;
    }
    forn (i, m) {
        cin >> a >> b;
        c[a][b + n] = c[b][a + n] = 200;
    }
    while (dfs(0, 200)){
        //cout << ans << endl;
        forn (i, 2 * n + 2) use[i] = 0;
        /*forn (i, 2 * n + 2) {
            forn (j, 2 * n + 2) cout << c[i][j] + f[i][j] << " ";
            cout << endl;
        }*/
    };
    if (ans  == sum) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = n + 1; j <= 2 * n; j++) {
                if (f[j][i] <= 0) cout << 0 << " ";
                else cout << f[j][i] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    cout << "NO";
    return 0;
}