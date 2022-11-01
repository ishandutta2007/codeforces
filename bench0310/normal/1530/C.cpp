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
        const int N=100;
        array<ll,N+1> a,b;
        a.fill(0); b.fill(0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        for(int i=0;i<n;i++)
        {
            int y;
            cin >> y;
            b[y]++;
        }
        auto score=[&](array<ll,N+1> &x,ll c)->ll
        {
            ll r=0;
            for(int i=100;i>=0;i--)
            {
                ll now=min(c,x[i]);
                r+=(now*i);
                c-=now;
            }
            return r;
        };
        ll l=n-1,r=n+(1ll<<40);
        while(l<r-1)
        {
            ll m=(l+r)/2;
            a[100]+=(m-n);
            b[0]+=(m-n);
            ll c=(m-(m/4));
            if(score(a,c)>=score(b,c)) r=m;
            else l=m;
            a[100]-=(m-n);
            b[0]-=(m-n);
        }
        cout << r-n << "\n";
    }
    return 0;
}