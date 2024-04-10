#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], b[200005], ind[200005], k[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
        cin >> b[i];

    for(int i=0; i<n; i++)
        ind[a[i]] = i;


    for(int i=0; i<n; i++)
        k[(i - ind[b[i]] + n) % n]++;

    int Max = 0;

    for(int i=0; i<200005; i++)
        Max = max(Max, k[i]);
    cout << Max;
}