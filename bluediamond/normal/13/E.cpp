#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
const int bucketS = 1000;
int n, m, tab[N];
int urm[N];
int steps[N];

void rebuild(int who)
{
        int l = 1 + who * bucketS;
        int r = min((who + 1) * bucketS, n);
        for (int j = r; j >= l; j--)
                if (j + tab[j] <= r)
                {
                        urm[j] = urm[j + tab[j]];
                        steps[j] = 1 + steps[j + tab[j]];
                }
                else
                {
                        urm[j] = j + tab[j];
                        steps[j] = 1;
                }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
                cin >> tab[i];
        for (int i = 0; i <= (n - 1) / bucketS; i++)
                rebuild(i);
        for (int i = 1; i <= m; i++)
        {
                int t;
                cin >> t;
                if (t == 1)
                {
                        int x;
                        cin >> x;
                        int cnt = 1;
                        while (urm[x] <= n)
                        {
                                cnt += steps[x];
                                x = urm[x];
                        }
                        while (x + tab[x] <= n)
                        {
                                cnt++;
                                x += tab[x];
                        }
                        cout << x << " " << cnt << "\n";
                }
                else
                {
                        int p, y;
                        cin >> p >> y;
                        tab[p] = y;
                        rebuild((p - 1) / bucketS);
                }
        }
}