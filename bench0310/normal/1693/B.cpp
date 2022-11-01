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
        vector<int> p(n+1,0);
        for(int i=2;i<=n;i++) cin >> p[i];
        vector<ll> val(n+1,0);
        vector<ll> l(n+1,0);
        vector<ll> r(n+1,0);
        for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
        int res=0;
        for(int i=n;i>=1;i--)
        {
            if(val[i]<l[i])
            {
                res++;
                val[p[i]]+=r[i];
            }
            else
            {
                val[i]=min(val[i],r[i]);
                val[p[i]]+=val[i];
            }
        }
        cout << res << "\n";
    }
    return 0;
}