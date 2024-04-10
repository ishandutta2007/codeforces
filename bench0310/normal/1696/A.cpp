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
        int n,z;
        cin >> n >> z;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            res=max(res,a|z);
        }
        cout << res << "\n";
    }
    return 0;
}