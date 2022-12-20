#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int d[10][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
            d[i][j] = (s[j] == '*');
    }
    int ans = 0, x = 0, y = 0;

    do {
        int nx = -1, ny = -1, bst = 100; 
        for (int i = x; i < r; i++)
            for (int j = y; j < c; j++)
                if (d[i][j] && i - x + j - y < bst)
                    bst = i - x + j - y, nx = i, ny = j;
        if (nx == -1)
            break;
        ans += 1;
        x = nx, y = ny;
        d[x][y] = 0;
    } while (x != r - 1 || y != c - 1);
    cout << ans << endl;
    

}