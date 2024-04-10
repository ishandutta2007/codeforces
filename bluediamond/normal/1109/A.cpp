#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (1 << 21);

int f[N][2];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n, Xor = 0;
        cin >> n;
        f[Xor][0]++;
        for (int i = 1; i <= n; i++)
        {
                int a;
                cin >> a;
                Xor ^= a;
                f[Xor][i % 2]++;
        }
        ll res = 0LL;
        for (int i = 0; i < N; i++)
        {
                for (int k = 0; k < 2; k++)
                {
                        ll a = f[i][k];
                        ll b = a - 1;
                        res += a * b / 2;
                }
        }
        cout << res << "\n";
        return 0;
}