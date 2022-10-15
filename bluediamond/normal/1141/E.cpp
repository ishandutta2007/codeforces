#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

ll hp;
int n;
ll prefix[N];
ll mip=0;


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>hp>>n;
        for(int i=1;i<=n;i++)
        {
                ll x;
                cin>>x;
                prefix[i]=prefix[i-1]+x;
                mip=min(mip,prefix[i]);
        }
        ll change=prefix[n];
        for(int i=1;i<=n;i++)
        {
                if(hp+prefix[i]<=0)
                {
                        cout<<i<<"\n";
                        return 0;
                }
        }
        if(change>=0)
        {
                cout<<"-1\n";
                return 0;
        }
        ll val=hp+mip;
        ll ch=-change;
        ll x=val/ch;
        ll res=x*(ll)n;
        hp+=x*change;
        for(int i=1;i<=n;i++)
        {
                res++;
                hp+=(prefix[i]-prefix[i-1]);
                if(hp<=0)
                {
                        cout<<res<<"\n";
                        return 0;
                }
        }
        for(int i=1;i<=n;i++)
        {
                res++;
                hp+=(prefix[i]-prefix[i-1]);
                if(hp<=0)
                {
                        cout<<res<<"\n";
                        return 0;
                }
        }
        cout<<"-1\n";
        return 0;
}
/**

**/