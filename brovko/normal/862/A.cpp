#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, a[105], used[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        used[a[i]]++;
    }

    int k = 0;
    for(int i = 0; i < x; i++)
        if(used[i] == 0)
            k++;

    k += used[x];

    cout << k;
}