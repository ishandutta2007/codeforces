#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int Hash(int x, int i)
{
    return ((x ^ i * i * x * x * x * x) + (x << 16 + i * 123456789)) % 998244353;
}

const int N = 3e5 + 5;
const int K = 50;
int t[N][K];

int sum(int r, int i)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r][i];

    return ans;
}

void inc(int i, int d, int j)
{
    for(; i < N; i |= i + 1)
        t[i][j] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int A[n][K];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < K; j++)
            A[i][j] = Hash(a[i], j);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < K; j++)
            inc(i, A[i][j], j);

    while(q--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;

            for(int j = 0; j < K; j++)
            {
                inc(i, -A[i][j] + Hash(x, j), j);
                A[i][j] = Hash(x, j);
            }
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;

            bool F = 1;

            for(int j = 0; j < K; j++)
                if((sum(r - 1, j) - sum(l - 2, j)) % k)
                    F = 0;

            if(F)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}