#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e6 + 7;
const int A = 26;
const int INF = (int) 1e9;

int urm_l[N][A];
int urm_r[N][A];
string a, b;
int n, m;

void build_l()
{
        for (int c = 0; c < A; c++)
        {
                urm_l[0][c] = -1;
        }
        urm_l[0][a[0] - 'a'] = 0;
        for (int i = 1; i < n; i++)
        {
                for (int c = 0; c < A; c++)
                {
                        urm_l[i][c] = urm_l[i - 1][c];
                }
                urm_l[i][a[i] - 'a'] = i;
        }
}

void build_r()
{
        for (int c = 0; c < A; c++)
        {
                urm_r[n - 1][c] = -1;
        }
        urm_r[n - 1][a[n - 1] - 'a'] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
                for (int c = 0; c < A; c++)
                {
                        urm_r[i][c] = urm_r[i + 1][c];
                }
                urm_r[i][a[i] - 'a'] = i;
        }
}

void print(int l, int r)
{
        for (int j = l; j <= r; j++)
        {
                cout << b[j];
        }
        cout << "\n";
        exit(0);
}

void print(int l1, int r1, int l2, int r2)
{
        for (int j = l1; j <= r1; j++)
        {
                cout << b[j];
        }
        for (int j = l2; j <= r2; j++)
        {
                cout << b[j];
        }
        cout << "\n";
        exit(0);
}

int pref[N];
int suf[N];

void build()
{
        int go = 0;
        for (int i = 0; i < m; i++)
        {
                if (go >= n || urm_r[go][b[i] - 'a'] == -1)
                {
                        pref[i] = INF;
                        go = INF;
                }
                else
                {
                        pref[i] = urm_r[go][b[i] - 'a'];
                        go = urm_r[go][b[i] - 'a'] + 1;
                }
        }
        go = n - 1;
        for (int i = m - 1; i >= 0; i--)
        {
                if (go < 0 || urm_l[go][b[i] - 'a'] == -1)
                {
                        suf[i] = -INF;
                        go = -INF;
                }
                else
                {
                        suf[i] = urm_l[go][b[i] - 'a'];
                        go = urm_l[go][b[i] - 'a'] - 1;
                }
        }
}

int calc_best()
{
        int best = 0;
        for (int i = 0; i < m; i++) if (pref[i] != INF) best = max(best, i + 1);
        for (int i = 0; i < m; i++) if (suf[i] != -INF) best = max(best, m - i);
        for (int i = 0; i < m; i++)
        {
                int ans = -1;
                int l = i + 1, r = m - 1;
                while (l <= r)
                {
                        int mid = (l + r) / 2;
                        if (pref[i] < suf[mid])
                        {
                                ans = mid;
                                r = mid - 1;
                        }
                        else
                        {
                                l = mid + 1;
                        }
                }
                if (ans == -1) continue;
                best = max(best, i + 1 + m - ans);
        }
        return best;
}

void print_best(int best)
{
        if (best == 0)
        {
                cout << "-\n";
                return;
        }
        for (int i = 0; i < m; i++) if (pref[i] != INF && best == i + 1) print(0, i);
        for (int i = 0; i < m; i++) if (suf[i] != -INF  && best == m - i) print(i, m - 1);
        for (int i = 0; i < m; i++)
        {
                int ans = -1;
                int l = i + 1, r = m - 1;
                while (l <= r)
                {
                        int mid = (l + r) / 2;
                        if (pref[i] < suf[mid])
                        {
                                ans = mid;
                                r = mid - 1;
                        }
                        else
                        {
                                l = mid + 1;
                        }
                }
                if (ans == -1) continue;
                if (i + 1 + m - ans == best)
                {
                        print(0, i, ans, m - 1);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

     //   freopen ("input", "r", stdin);

        cin >> a >> b;
        n = (int) a.size();
        m = (int) b.size();

        /// ramane un prefix si un sufix din b

        build_l();
        build_r();
        build();

      //  for (int i = 0; i < m; i++) cout << pref[i] << " "; cout << "\n";
      //  for (int i = 0; i < m; i++) cout << suf[i] << " "; cout << "\n";

        print_best(calc_best());

        return 0;
}