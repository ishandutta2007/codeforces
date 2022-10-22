#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[100005], Max, ind;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<k; i++)
    {
        cin >> a[i];
        if(n / a[i] * a[i] > Max)
        {
            Max = n / a[i] * a[i];
            ind = i;
        }
    }

    cout << ind + 1 << ' ' << n / a[ind];
}