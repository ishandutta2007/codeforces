#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const int M = (int) 1e9 + 7;
int n;
int all;
int sol;
bitset<N> act1;
bitset<N> act2;

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = (ll) r * a % M;
        }
        a = (ll) a * a % M;
        b /= 2;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (act1[x] == 0)
        {
            act1[x] = 1;
        }
        else
        {
            act2[x] = 1;
        }
        if (act1[y] == 0)
        {
            act1[y] = 1;
        }
        else
        {
            act2[y] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        all += (act2[i] == 0);
    }
    cout << ((ll) all * pw(2, n - (all - 1)) + (ll) (n - all) * pw(2, n - all)) % M << "\n";
}