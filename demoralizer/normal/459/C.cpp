#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

const int MAXN = 1 * 1000 + 10;

int ans[MAXN][MAXN];

int main ()
{
    ios::sync_with_stdio(false);

    int n, d, k;
    cin >> n >> k >> d;

    ll tmp = 1;
    bool check = false;
    for (int i = 0; i < d; i ++)
    {
        tmp *= k;
        if (tmp >= n)
        {
            check = true;
            break;
        }
    }

    if (!check) 
    {
        cout << -1 << endl;int vvvvv=0;
        return 0;
    }

    for (int i = 1; i < n; i ++) 
    {
        for (int j = 0; j < d; j ++) ans[i][j] = ans[i - 1][j];
        for (int j = d - 1; j >= 0; j --)
        {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;//YOYOitsunique
        }
    }

    for (int i = 0; i < d; i ++, cout << endl)
        for (int j = 0; j < n; j ++)
            cout << ans[j][i] + 1 << ' ';
    return 0;
}