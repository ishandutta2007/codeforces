#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a[10005], Max, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        Max=max(Max, a[i]);
        if(Max==i+1)
            k++;
    }
    cout << k;
}