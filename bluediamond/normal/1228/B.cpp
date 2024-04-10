#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
        a += b;
        if (a >= MOD)
                return a - MOD;
        if (a < 0)
                return a + MOD;
        return a;
}

int mul(int a, int b)
{
        return a * (ll) b % MOD;
}

const int N = 1000 + 7;
int n, m, a[N][N];

void make(int i, int j, int x)
{
        if (1 <= i && 1 <= j && i <= n && j <= m)
                if (a[i][j] == -1)
                        a[i][j] = x;
                else
                        if (a[i][j] != x)
                        {
                                cout << "0\n";
                                exit(0);
                        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        a[i][j] = -1;
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                for (int j = 1; j <= x; j++)
                        make(i, j, 1);
                make(i, x + 1, 0);
        }
        for (int j = 1; j <= m; j++)
        {
                int x;
                cin >> x;
                for (int i = 1; i <= x; i++)
                        make(i, j, 1);
                make(x + 1, j, 0);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        if (a[i][j] == -1)
                                ans = mul(ans, 2);
        cout << ans << "\n";
}