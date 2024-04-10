#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int M = 998244353;

int rep(int x) {
        x %= M;
        if (x < 0)
                x += M;
        return x;
}

const int N = 400 + 7;
int n, f[N], cnt[N][N][2][2], cnt1[N], dp[2][N][N][3][3], cnt2[N][N];

signed main() {
        cin >> n;
        for (int i = 0; i < 26; i++)
                cin >> f[i];

        /// avem f[i] >= n / 3 pentru fiecare i
        /// trebuie sa respectam restrictiile pt fiecare i in acelasi timp
        /// daca Nu respectam o restrictie => avem use[i] > f[i] > n/3
        /// de aici rezulta ca NU putem avea i,j,k care nu respecta cond in acelasi timp
        /// => maxim 2 indici NU respecta restrictiile in acelasi timp
        /// => facem pinex
        /// toti respecta = total - unul nu respecta + o pereche de 2 nu respecta
        /// total = fara restrictie
        int total = 26 * 26;
        for (int i = 3; i <= n; i++)
                total = rep(total * 25);
        int ret = total;
        for (int e1 = 0; e1 <= 1; e1++)
                for (int e2 = 0; e2 <= 1; e2++) {
                        int val = 1;
                        if (!e1)
                                val *= 25;
                        if (!e2)
                                val *= 25;
                        cnt[2][e1 + e2][e1][e2] = val;
                }
        for (int l = 2; l < n; l++)
                for (int tot = 0; tot <= n; tot++) {
                        for (int ant1 = 0; ant1 <= 1; ant1++)
                                for (int ant2 = 0; ant2 <= 1; ant2++) {
                                        for (int now = 0; now <= 1; now++) {
                                                if (now && ant1)
                                                        continue;
                                                int coef;
                                                if (now)
                                                        coef = 1;
                                                else {
                                                        if (ant1)
                                                                coef = 25;
                                                        else
                                                                coef = 24;
                                                }
                                                cnt[l + 1][tot + now][ant2][now] = rep(cnt[l + 1][tot + now][ant2][now] + cnt[l][tot][ant1][ant2] * coef);
                                        }
                                }
                }
        for (int tot = 0; tot <= n; tot++)
                for (int ant1 = 0; ant1 <= 1; ant1++)
                        for (int ant2 = 0; ant2 <= 1; ant2++)
                                cnt1[tot] = rep(cnt1[tot] + cnt[n][tot][ant1][ant2]);
        for (int i = 0; i < 26; i++)
                for (int j = f[i] + 1; j <= n; j++)
                        ret = rep(ret - cnt1[j]);
        for (int e1 = 0; e1 <= 2; e1++)
                for (int e2 = 0; e2 <= 2; e2++) {
                        int val = 1;
                        if (!e1)
                                val *= 24;
                        if (!e2)
                                val *= 24;
                        dp[0][(e1 == 1) + (e2 == 1)][(e1 == 2) + (e2 == 2)][e1][e2] = val;
                }
        for (int l = 2; l < n; l++) {
                int it = l % 2, nxt = (it ^ 1);
                for (int tot1 = 0; tot1 <= l + 1; tot1++)
                        for (int tot2 = 0; tot1 + tot2 <= l + 1; tot2++)
                                for (int ant1 = 0; ant1 <= 2; ant1++)
                                        for (int ant2 = 0; ant2 <= 2; ant2++)
                                                dp[nxt][tot1][tot2][ant1][ant2] = 0;
                for (int tot1 = 0; tot1 <= l; tot1++)
                        for (int tot2 = 0; tot1 + tot2 <= l; tot2++)
                                for (int ant1 = 0; ant1 <= 2; ant1++)
                                        for (int ant2 = 0; ant2 <= 2; ant2++) {
                                                if (!dp[it][tot1][tot2][ant1][ant2])
                                                        continue;
                                                for (int now = 0; now <= 2; now++) {
                                                        int coef;
                                                        if (now && ant1 && now == ant1)
                                                                continue;
                                                        if (now)
                                                                coef = 1;
                                                        else {
                                                                if (ant1)
                                                                        coef = 24;
                                                                else
                                                                        coef = 23;
                                                        }
                                                        dp[nxt][tot1 + (now == 1)][tot2 + (now == 2)][ant2][now] = rep(dp[nxt][tot1 + (now == 1)][tot2 + (now == 2)][ant2][now] + dp[it][tot1][tot2][ant1][ant2] * coef);
                                                }
                                        }
        }
        for (int tot1 = 0; tot1 <= n; tot1++)
                for (int tot2 = 0; tot2 <= n; tot2++)
                        for (int ant1 = 0; ant1 <= 2; ant1++)
                                for (int ant2 = 0; ant2 <= 2; ant2++)
                                        cnt2[tot1][tot2] = rep(cnt2[tot1][tot2] + dp[n % 2][tot1][tot2][ant1][ant2]);
        for (int i = 0; i < 26; i++)
                for (int j = 0; j < i; j++) {
                        for (int ci = f[i] + 1; ci <= n; ci++)
                                for (int cj = f[j] + 1; cj <= n; cj++)
                                        ret = rep(ret + cnt2[ci][cj]);
                }
        cout << ret << "\n";
}