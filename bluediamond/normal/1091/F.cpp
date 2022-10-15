#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

const int N=(int)1e5+5;

struct info
{
    ll l;
    string t;
};

int n;
info v[N];

ll w=-1;

ll e=0LL;

ll add[N];
ll a[N];
ll co=0LL;
ll mis[N];

ll rem[N]; /// remain

ll go[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input","r",stdin);
    //freopen("output","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].l;
        rem[i]=v[i].l;
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        v[i].t=s[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i].t=="W" && w==-1)
        {
            w=i;
        }
        if(v[i].t=="W" || v[i].t=="G")
        {
            e+=v[i].l;
        }
        else
        {
            if(e<v[i].l)
            {
                ll need=v[i].l-e;
                e+=need;
                if(w==-1)
                {
                    co+=5*need;
                    add[1]+=need;
                }
                else
                {
                    co+=3*need;
                    add[(int)w]+=need;
                }
                add[i]-=need;
            }
            e-=v[i].l;
        }
        a[i]=e;
    }
    ll cur=0LL;
    for(int i=1;i<=n;i++)
    {
        cur+=add[i];
        a[i]+=cur;
    }
    mis[n]=a[n];
    for(int i=n-1;i>=1;i--)
    {
        mis[i]=min(mis[i+1],a[i]);
    }
    ll lft=a[n];
    lft/=2;
    cur=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].t=="G") /// grass
        {
            ll k=(mis[i]-cur)/2;
            ll t=min(lft,k);
            t=min(t,rem[i]);
            lft-=t;
            go[i]+=2*t;
            cur+=go[i];
            rem[i]-=t;

     ///       cout<<t<<"\n";
        }
    }
    cur=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].t=="W") /// water
        {
            ll k=(mis[i]-cur)/2;
            ll t=min(lft,k);
            t=min(t,rem[i]);
            rem[i]-=t;
            lft-=t;
            cur+=go[i];
            cur+=2*t;


        }
    }
  //  for(ll i=1;i<=n;i++) cout<<rem[i]<<" ";cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(v[i].t=="G") co+=rem[i]*5;
        if(v[i].t=="W") co+=rem[i]*3;
        if(v[i].t=="L") co+=rem[i];
    }
  //  cout<<co<<"\n";
    for(int i=1;i<=n;i++)
    {
        ll k=v[i].l-rem[i];
        co+=k;
    }
    cout<<fixed<<setprecision(0)<<co<<"\n";

    return 0;
}
/**



2
2 1
WL

4
3 4 10 3
GWLW

**/