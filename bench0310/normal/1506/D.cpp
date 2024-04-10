#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<int,int> m;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            mx=max(mx,++m[a]);
        }
        if(mx>n/2) cout << n-2*(n-mx) << "\n";
        else cout << (n&1) << "\n";
    }
    return 0;
}