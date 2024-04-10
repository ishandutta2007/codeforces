#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, q;

const int SZ = (int) 5e5 + 7;
vector <int> out[SZ];
int in[SZ];

int kek[SZ][19];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

       // freopen ("input", "r", stdin);
       // freopen ("output", "w", stdout);

        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
                int l, r;
                cin >> l >> r;
                l++;
                r++;
                out[l - 1].push_back(r);
                in[r]++;
        }

        multiset <int> s;

        for (int i = SZ - 1; i >= 0; i--)
        {
                for (int j = 1; j <= in[i]; j++)
                {
                        s.insert(-i);
                }
                for (auto &r : out[i])
                {
                        auto it = s.find(-r);
                        s.erase(it);
                }
                if (s.empty())
                {
                        kek[i][0] = -1;
                }
                else
                {
                        kek[i][0] = -*s.begin();
                }
        }

        for (int k = 1; k <= 18; k++)
        {
                for (int i = 1; i < SZ; i++)
                {
                        if (kek[i][k - 1] == -1)
                        {
                                kek[i][k] = -1;
                        }
                        else
                        {
                                int pz = kek[i][k - 1];
                                if (1 <= pz && pz < SZ)
                                {
                                        kek[i][k] = kek[pz][k - 1];
                                }
                                else
                                {
                                        kek[i][k] = -1;
                                }
                        }
                }
        }

        while (q--)
        {
                int l, r;
                cin >> l >> r;
                l++;
                r++;
                int cost = 0;
                for (int step = 18; step >= 0; step--)
                {
                        int pz;
                        if (kek[l][step] == -1)
                        {
                                pz = (1 << 30);
                        }
                        else
                        {
                                pz = kek[l][step];
                        }
                        if (pz < r)
                        {
                                cost += (1 << step);
                                l = pz;
                        }
                }
                l = kek[l][0];
                if (l >= r)
                {
                        cout << cost + 1 << "\n";
                }
                else
                {
                        cout << "-1\n";
                }
        }

}