#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, m, used[7], k1, k2, ans;
vector <int> v;

void rec(int d)
{
    if(d == k1 + k2)
    {
        int x = 0, y = 0;

        for(int i = 0; i < k1; i++)
            x = x * 7 + v[i];

        for(int i = k1; i < k1 + k2; i++)
            y = y * 7 + v[i];

        if(x < n && y < m)
            ans++;

        return;
    }

    for(int i = 0; i < 7; i++)
        if(used[i] == 0)
        {
            used[i] = 1;
            v.push_back(i);

            rec(d + 1);

            used[i] = 0;
            v.pop_back();
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int N = n - 1;
    int M = m - 1;

    while(N)
    {
        N /= 7;
        k1++;
    }

    if(k1 == 0)
        k1++;

    while(M)
    {
        M /= 7;
        k2++;
    }

    if(k2 == 0)
        k2++;

    rec(0);

    cout << ans;
}