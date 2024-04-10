#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int n, a[1000005], b[10000005], Min[10000005][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[a[i]]++;

    for(int i = 0; i < 10000005; i++)
    {
        Min[i][0] = 1e9;
        Min[i][1] = 1e9;
    }

    for(int i = 1; i < 10000005; i++)
        for(int j = i; j < 10000005; j += i)
        {
            if(b[j] > 0)
                Min[i][1] = min(Min[i][1], j);

            if(b[j] > 1)
                Min[i][0] = min(Min[i][0], j);

            if(Min[i][0] > Min[i][1])
                swap(Min[i][0], Min[i][1]);
        }

    li x = 0, y = 0, ans = 1e18;

    for(int i = 1; i < 10000005; i++)
    {
        if(Min[i][1] < 1e8 && Min[i][0] * 1ll * Min[i][1] / __gcd(Min[i][0], Min[i][1]) < ans)
        {
            ans = Min[i][0] * 1ll * Min[i][1] / __gcd(Min[i][0], Min[i][1]);
            x = Min[i][0];
            y = Min[i][1];
        }
    }

    int i = 0, j = 0;

    while(a[i] != x)
        i++;

    while(a[j] != y || i == j)
        j++;

    if(i > j)
        swap(i, j);

    cout << i + 1 << ' ' << j + 1;
}