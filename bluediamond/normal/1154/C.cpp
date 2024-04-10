#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll x[]={0,1,2,0,2,1,0};
ll a[100],b[100];

bool check()
{
        for(ll j=0;j<=6;j++)
        {
                if(a[x[j]]<0)
                {
                        return 0;
                }
        }
        return 1;
}

bool pot(ll go,ll cnt)
{
        a[0]=b[0];
        a[1]=b[1];
        a[2]=b[2];
        for(ll j=go;j<=6;j++)
        {
                a[x[j]]--;
                cnt--;
                if(cnt==0)
                {
                        return check();
                }
        }
        ll hv=cnt/7;
        for(ll j=0;j<7;j++)
        {
                a[x[j]]-=hv;
        }
        cnt%=7;
        for(ll j=0;j<=6;j++)
        {
                if(cnt==0)
                {
                        return check();
                }
                a[x[j]]--;
                cnt--;
                if(cnt==0)
                {
                        return check();
                }
        }
        return check();
}

ll ans=0;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>b[0]>>b[1]>>b[2];
        for(ll j=0;j<=6;j++)
        {
                ll l=0;
                ll r=2e9;
                while(l<=r)
                {
                        ll m=(l+r)/2;
                        if(pot(j,m))
                        {
                                l=m+1;
                                ans=max(ans,m);
                        }
                        else
                        {
                                r=m-1;
                        }
                }
        }
        cout<<ans<<"\n";
        return 0;
}
/**

700000000 700000000 700000000


        mon 0
        tue 1
        wen 2
        thu 0
        fri 2
        sat 1
        sun 0

        on Mondays, Thursdays and Sundays he eats fish food;
        on Tuesdays and Saturdays he eats rabbit stew;
        on other days of week he eats chicken stake.

**/