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
        ll p=1;
        ll s=0;
        ll m=0;
        for(int i=0;i<n;i++)
        {
            int b;
            cin >> b;
            while((b%2)==0)
            {
                b/=2;
                p*=2;
            }
            s+=b;
            m=max(m,ll(b));
        }
        cout << s-m+m*p << "\n";
    }
    return 0;
}