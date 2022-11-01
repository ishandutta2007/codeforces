#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    const ll inf=(1ll<<60);
    while(z--)
    {
        ll n;
        cin >> n;
        vector<ll> t(n+2,0);
        t[n+1]=inf;
        vector<ll> x(n+1,0);
        for(ll i=1;i<=n;i++) cin >> t[i] >> x[i];
        int res=0;
        ll pos=0;
        ll dest=0;
        ll tdone=0;
        for(int i=1;i<=n;i++)
        {
            if(tdone>t[i-1])
            {
                ll mv=min(tdone,t[i])-t[i-1];
                if(pos<dest) pos=min(dest,pos+mv);
                else pos=max(dest,pos-mv);
            }
            if(tdone<=t[i])
            {
                dest=x[i];
                tdone=t[i]+abs(pos-dest);
            }
            ll to=0;
            ll mv=min(tdone,t[i+1])-t[i];
            if(pos<dest) to=min(dest,pos+mv);
            else to=max(dest,pos-mv);
            ll one=min(pos,to);
            ll two=max(pos,to);
            if(one<=x[i]&&x[i]<=two) res++;
        }
        cout << res << "\n";
    }
    return 0;
}