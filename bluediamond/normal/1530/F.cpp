
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 21;

const int MOD = 31607;

int pwr (int a, int b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return a * pwr(a, (b ^ 1)) % MOD;
    int aux = pwr(a, (b >> 1));
    return aux * aux % MOD;
}

int inv[MOD];

int n;

int p[N_MAX][N_MAX];

int prec[N_MAX];

int col[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < MOD; i++)
        inv[i] = pwr(i, MOD - 2);
    for(int j = 0; j < n; j++)
        prec[j] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> p[i][j];

            p[i][j] = p[i][j] * inv[10000] % MOD;

            prec[j] = prec[j] * p[i][j] % MOD;
        }

    int answer = 1;

    for(int mask = 0; mask < (1 << n); mask++)
        for(int d1 = 0; d1 < 2; d1++)
            for(int d2 = 0; d2 < 2; d2++)
            {
                for(int j = 0; j < n; j++)
                    col[j] = 1;

                int prob = 1;
                if(d1 == true)
                {
                    for(int i = 0; i < n; i++)
                    {
                        int j = i;

                        col[j] = col[j] * p[i][j] % MOD;
                    }
                }
                if(d2 == true)
                {
                    for(int i = 0; i < n; i++)
                    {
                        int j = (n - 1) - i;
                        if(d1 == true && i - j == 0)
                            continue;

                        col[j] = col[j] * p[i][j] % MOD;
                    }
                }
                for(int i = 0; i < n; i++)
                    if((mask >> i) & 1)
                    {
                        for(int j = 0; j < n; j++)
                        {
                            if(d1 == true && i - j == 0)
                                continue;
                            if(d2 == true && i + j == n - 1)
                                continue;

                            col[j] = col[j] * p[i][j] % MOD;
                        }
                    }
                for(int j = 0; j < n; j++)
                {
                    prob = prob * col[j] % MOD;
                    col[j] = prec[j] * inv[col[j]] % MOD;
                }

                for(int j = 0; j < n; j++)
                    prob = prob * (1 - col[j]) % MOD;

                int cnt = __builtin_popcount(mask) + d1 + d2;

                if(cnt & 1)
                {
                    answer += prob;
                    if(answer >= MOD)
                        answer -= MOD;
                }
                else
                {
                    answer -= prob;
                    if(answer < 0)
                        answer += MOD;
                }
            }

    cout << answer << "\n";

    return 0;
}