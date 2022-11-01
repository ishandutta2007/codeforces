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
        ll k;
        cin >> n >> k;
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll res=(1ll<<60);
        if(max(l1,l2)>=min(r1,r2)) //no intersection
        {
            ll dist=max(l1,l2)-min(r1,r2);
            ll x=max(r1,r2)-min(l1,l2);
            for(ll i=1;i<=n;i++)
            {
                ll now=dist*i;
                ll z=min(k,x*i);
                now+=z;
                now+=(2*(k-z));
                res=min(res,now);
            }
        }
        else //intersection
        {
            ll y=min(r1,r2)-max(l1,l2);
            k-=min(k,y*n);
            ll x=max(r1,r2)-min(l1,l2)-y;
            ll z=min(k,x*n);
            res=min(k,z);
            res+=(2*(k-z));
        }
        cout << res << "\n";
    }
    return 0;
}