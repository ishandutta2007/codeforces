#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=200000+7;
const ll INF=(ll)1e9+7;

ll n;
ll t[4*N];
ll lazy[4*N];

void push(ll nod)
{
        t[2*nod]+=lazy[nod];
        t[2*nod+1]+=lazy[nod];
        lazy[2*nod]+=lazy[nod];
        lazy[2*nod+1]+=lazy[nod];
        lazy[nod]=0;
}

void upd(ll nod,ll tl,ll tr,ll l,ll r,ll add)
{
        if(tr<l || r<tl)
        {
                return;
        }
        if(l<=tl && tr<=r)
        {
                t[nod]+=add;
                lazy[nod]+=add;
        }
        else
        {
                push(nod);
                ll tm=(tl+tr)>>1;
                upd(2*nod,tl,tm,l,r,add);
                upd(2*nod+1,tm+1,tr,l,r,add);
                t[nod]=min(t[2*nod],t[2*nod+1]);
        }
}

ll get(ll nod,ll tl,ll tr,ll l,ll r)
{
        if(tr<l || r<tl)
        {
                return INF;
        }
        if(l<=tl && tr<=r)
        {
                return t[nod];
        }
        else
        {
                push(nod);
                ll tm=(tl+tr)>>1;
                return  min(get(2*nod,tl,tm,l,r),get(2*nod+1,tm+1,tr,l,r));
        }
}

void upd(ll l,ll r,ll add)
{
        if(l<=r)
        {
                upd(1,1,n,l,r,add);
        }
        else
        {
                upd(1,1,n,l,n,add);
                upd(1,1,n,1,r,add);
        }
}

ll get(ll l,ll r)
{
        if(l<=r)
        {
                return get(1,1,n,l,r);
        }
        else
        {
                return min(get(1,1,n,l,n),get(1,1,n,1,r));
        }
}

char s[100];
ll p;

ll getnum()
{
        ll sgn=1;
        if(s[p]=='-')
        {
                sgn=-1;
                p++;
        }
        ll x=0;
        while('0'<=s[p] && s[p]<='9')
        {
                x=10*x+s[p]-'0';
                p++;
        }
        return x*sgn;
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
                ll x;
                cin>>x;
                upd(i,i,x);
        }
        ll q;
        cin>>q;
        cin.get();
        while(q--)
        {
                cin.getline(s,100);
                p=0;
                ll sz=strlen(s);
                vector<ll>a;
                while(p<sz)
                {
                        a.push_back(getnum());
                        p++;
                }
                a[0]++;
                a[1]++;
                if(a.size()==2)
                {
                        cout<<get(a[0],a[1])<<"\n";
                }
                else
                {
                        upd(a[0],a[1],a[2]);
                }
        }
        return 0;
}