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
        vector<int> a(n+1,0);
        vector<int> c(2,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]&=1;
            c[a[i]]++;
        }
        if(abs(c[0]-c[1])<=1)
        {
            ll res=(1ll<<60);
            auto go=[&](int x)
            {
                ll now=0;
                int zero=0;
                int one=0;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==0)
                    {
                        zero++;
                        now+=abs(one-(zero-1+x));
                    }
                    else one++;
                }
                res=min(res,now);
            };
            if(c[0]>c[1]) go(0);
            else if(c[1]>c[0]) go(1);
            else
            {
                go(0);
                go(1);
            }
            cout << res << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}