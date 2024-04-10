#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int L = 20;
int n;
int lg[N];

int ggcd(int a, int b)
{
        if (b == 0)
                return a;
        return ggcd(b, a % b);
}

int ret[N][L];

int get(int l, int r)
{
        int k = lg[r - l + 1];
        return ggcd(ret[l][k], ret[r - (1 << k) + 1][k]);
}

map <int, ll> sol;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;
        for (int i = 2; i <= n; i++)
                lg[i] = 1 + lg[i / 2];
        for (int i = 1; i <= n; i++)
                cin >> ret[i][0];
        for (int k = 1; (1 << k) <= n; k++)
                for (int i = 1; i + (1 << k) - 1 <= n; i++)
                        ret[i][k] = ggcd(ret[i][k - 1], ret[i + (1 << (k - 1))][k - 1]);
        for (int l = 1; l <= n; l++)
        {
                int r = l;
                while (r <= n)
                {
                        int lo = r + 1, hi = n;
                        int ans = r;
                        while (lo <= hi)
                        {
                                int mid = (lo + hi) / 2;
                                if (get(l, mid) == get(l, r))
                                {
                                        ans = mid;
                                        lo = mid + 1;
                                }
                                else
                                        hi = mid - 1;
                        }
                        sol[get(l, r)] += ans - r + 1;
                        r = ans + 1;
                }
        }
        int q;
        cin >> q;
        while (q--)
        {
                int x;
                cin >> x;
                cout << sol[x] << "\n";
        }
}