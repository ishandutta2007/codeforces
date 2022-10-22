#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int t, x1, x2, y1, y2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int a=x2-x1+1;
        int b=y2-y1+1;
        if(a>b)
            swap(a, b);
        cout << 2*a*(a-1)/2+(a-1)*(b-a-1)+1 << "\n";
    }
}