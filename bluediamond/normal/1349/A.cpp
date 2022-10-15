#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
int n, f[N];
bool p[N];
vector<int> e[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                int a;
                cin >> a;
                f[a]++;
        }
        p[2] = 1;
        for (int i = 3; i < N; i += 2)
                p[i] = 1;
        for (int i = 3; i * i < N; i += 2)
                if (p[i])
                        for (int j = i * i; j < N; j += 2 * i)
                                p[j] = 0;
        for (int d = 2; d < N; d++)
                if (p[d])
                {
                        for (int i = d; i < N; i += d)
                        {
                                if (f[i])
                                {
                                        int cnt = 0, j = i;
                                        while (j % d == 0)
                                        {
                                                j /= d;
                                                cnt++;
                                        }
                                        for (int j = 1; j <= f[i]; j++)
                                                e[d].push_back(cnt);
                                }
                        }
                }
        ll sol = 1;
        for (int d = 2; d < N; d++)
        {
                if ((int) e[d].size() >= n - 1)
                {
                        while ((int) e[d].size() < n)
                                e[d].push_back(0);
                        sort(e[d].begin(), e[d].end());
                        for (int j = 1; j <= e[d][1]; j++)
                                sol *= d;
                }
        }
        cout << sol << "\n";
}