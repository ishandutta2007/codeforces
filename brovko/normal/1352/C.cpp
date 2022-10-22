#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k%(n-1)==0)
            cout << k/(n-1)*n-1 << "\n";
        else
        cout << k/(n-1)*n+k%(n-1) << "\n";
    }
}