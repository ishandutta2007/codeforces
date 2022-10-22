#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, g, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> g >> b;
        int x=(n+1)/2/g;
        int y=x*(g+b);
        int ans=y+(n+1)/2-x*g;
        if(y==ans)
            ans-=b;
        cout << max(ans, n) << endl;
    }
}