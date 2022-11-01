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
        int n,k;
        cin >> n >> k;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int p;
            cin >> p;
            res+=(i<=k&&p>k);
        }
        cout << res << "\n";
    }
    return 0;
}