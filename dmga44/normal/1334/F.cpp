#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 500005

ll a[MAXN],p[MAXN],b[MAXN],abi1[MAXN],abi2[MAXN],sum1[MAXN],sum2[MAXN],sum3[MAXN],sum4[MAXN];
ll ant[MAXN],pos[MAXN];
vector<int> pi[MAXN];
vector<pii> ants[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi1[p]+=v;
        p+=(p&-p);
    }
}

ll query(int p)
{
    ll res=0;
    while(p>0)
    {
        res+=abi1[p];
        p-=(p&-p);
    }
    return res;
}

void update2(int p,int v)
{
    while(p<MAXN)
    {
        abi2[p]+=v;
        p+=(p&-p);
    }
}

ll query2(int p)
{
    ll res=0;
    while(p>0)
    {
        res+=abi2[p];
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> p[i];

    int m;
    cin >> m;
    bool ok=1;
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        pos[b[i]]=i+1;
        if(!i)
            ant[b[i]]=-1;
        else
        {
            ant[b[i]]=b[i-1];
            ok&=(b[i]>b[i-1]);
        }
    }

    int pn=0,pm=0;
    while(pn<n && pm<m)
    {
        while(pn<n && a[pn]!=b[pm])
            pn++;
        if(pn!=n)
        {
            pn++;
            pm++;
        }
    }

    if(pm!=m || !ok)
    {
        db("NO")
        return 0;
    }
    db("YES")
    ll st=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]<0)
            update2(a[i],p[i]);
        if(pos[a[i]])
        {
            pi[pos[a[i]]-1].push_back(i);
            ll x1=query(a[i]);
            sum1[i]=st-x1;
            ll x2=query(ant[a[i]]);
            sum2[i]=st-x2;
            sum3[i]=query2(a[i]);
            sum4[i]=query2(ant[a[i]]);
        }
        update(a[i],p[i]);
        st+=p[i];
    }
    ll s1l=st-query(b[m-1]);
    ll s2l=query2(b[m-1]);

    ll res=1e17;
    for(int i=0;i<m;i++)
    {
        reverse(all(pi[i]));

        for(auto y : pi[i])
        {
            ll v;
            if(i==0)
                v=sum2[y]-sum1[y]+sum4[y]-sum3[y];
            else
            {
                int p=lower_bound(all(ants[i-1]),pii(y,0))-ants[i-1].begin();
                if(!p)
                    v=1e17;
                else
                    v=ants[i-1][p-1].second+sum2[y]-sum1[y]+sum4[y]-sum3[y];
            }
            if(i==m-1)
            {
                v+=s1l+s2l;
                res=min(res,v);
            }

            while(!ants[i].empty() && ants[i].back().second>=v)
                ants[i].pop_back();
            ants[i].push_back(pii(y,v));
        }

        reverse(all(ants[i]));
    }
    db(res)

    return 0;
}
/**
11
4 1 3 3 7 8 7 9 10 7 11
3 5 0 -2 5 3 6 7 8 2 4
3
3 7 10
**/