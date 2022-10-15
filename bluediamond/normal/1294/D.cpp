#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int x;
map<int, int> f;
int full = 0;
int mx = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        r %= x;
        f[r]++;
        while (1)
        {
            while (f[mx + 1])
            {
                mx++;
            }
            if (mx == x - 1)
            {
                mx = -1;
                full++;
                for (int j = 0; j < x; j++)
                {
                    f[j]--;
                }
                while (f[mx + 1])
                {
                    mx++;
                }
            }
            else
            {
                break;
            }
        }
        cout << full * x + mx + 1 << "\n";
    }



}