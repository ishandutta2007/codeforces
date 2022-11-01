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
        ll a,b;
        cin >> a >> b;
        int res=35;
        for(int i=0;i<=35;i++)
        {
            ll x=a;
            int now=i;
            if(b>1)
            {
                while(x>0)
                {
                    x/=b;
                    now++;
                }
                res=min(res,now);
            }
            b++;
        }
        cout << res << "\n";
    }
    return 0;
}