#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 7;

int n;
string s, t;
int a[N], b[N], v[N];
int totb;
int f[3];
int c[3];

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        cin >> s >> t;
        for(int i = 1; i <= n; i++)
        {
                a[i] = (s[i - 1] - '0');
                b[i] = (t[i - 1] - '0');
                v[i] = a[i] + b[i];
                f[v[i]]++;
                totb += b[i];
        }
        for(c[0] = 0; c[0] <= f[0]; c[0]++)
        {
                for(c[1] = 0; c[1] <= f[1] && c[0] + c[1] <= n / 2; c[1]++)
                {
                        c[2] = n / 2 - c[0] - c[1];
                        int val = c[1] + 2 * c[2];
                        if(val != totb || c[2] > f[2])
                        {
                                continue;
                        }
                        vector <int> res;
                        for(int k = 0; k < 3; k++)
                        {
                                for(int i = 1; i <= n && c[k] > 0; i++)
                                {
                                        if(v[i] == k)
                                        {
                                                res.push_back(i);
                                                c[k]--;
                                        }
                                }
                        }
                        sort(res.begin(), res.end());
                        for(auto &x : res)
                        {
                                cout << x << " ";
                        }
                        cout << "\n";
                        return 0;
                }
        }
        cout << "-1\n";
        return 0;
}