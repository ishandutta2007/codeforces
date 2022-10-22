#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a, b, x[105], y[105], Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
    {
        if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        if(x[i] + x[j] <= b && y[i] <= a && y[j] <= a)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        swap(x[i], y[i]);

        if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        if(x[i] + x[j] <= b && y[i] <= a && y[j] <= a)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        swap(x[j], y[j]);

        if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        if(x[i] + x[j] <= b && y[i] <= a && y[j] <= a)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        swap(x[i], y[i]);

        if(x[i] + x[j] <= a && y[i] <= b && y[j] <= b)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);

        if(x[i] + x[j] <= b && y[i] <= a && y[j] <= a)
            Max = max(Max, x[i] * y[i] + x[j] * y[j]);
    }

    cout << Max;
}