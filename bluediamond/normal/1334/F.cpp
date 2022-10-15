#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int) 5e5+7;
const ll INF=(ll)1e18;
int n;
int a[N];
int c[N];
int m;
int b[N];
int idb[N];
ll negp[N];
ll sol[N];
int ant[N];
vector<int> where[N];

ll neg(int l,int r)
{
        return negp[r]-negp[l-1];
}

map<pair<int,int>,ll> kek;

ll pref(int p,int x)
{
        return kek[{p,x}];
}

ll poz(int l,int r,int x)
{
        return pref(r,x)-pref(l-1,x);
}

vector<int> q[N];

void add(int p,int x)
{
        q[x].push_back(p);
}

void add(int l,int r,int x)
{
        add(r,x);
        add(l-1,x);
}

ll tree[N];

void addT(int i,ll x)
{
        while (i<=n)
        {
                tree[i]+=x;
                i+=i&(-i);
        }
}

ll prefT(int i)
{
        ll sol=0;
        while (i>=1)
        {
                sol+=tree[i];
                i-=i&(-i);
        }
        return sol;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n;
        for (int i=1;i<=n;i++)
                cin>>a[i];
        for (int i=1;i<=n;i++)
        {
                cin>>c[i];
                if (c[i]<=0)
                {
                        negp[i]=c[i];
                }
                else
                {
                        where[a[i]].push_back(i);
                }
                negp[i]+=negp[i-1];
        }
        cin>>m;
        for (int i=1;i<=m;i++)
        {
                cin>>b[i];
                idb[b[i]]=i;
        }
        for (int i=1;i<m;i++)
                if (b[i]>=b[i+1])
                {
                        cout<<"NO\n";
                        return 0;
                }
        for (int i=1;i<=m;i++)
                sol[i]=INF;
        for (int p=1;p<=n;p++)
        {
                int i=idb[a[p]];
                if (i==0)
                        continue;
                add(ant[i-1]+1,p-1,b[i-1]+1);
                add(ant[i]+1,p,b[i]+1);
        }
        add(ant[m]+1,n,b[m]+1);
        for (int i=1;i<=m;i++)
                ant[i]=0;
        for (int x=n;x>=1;x--)
        {
                for (auto &i : where[x])
                {
                        addT(i,c[i]);
                }
                for (auto &i : q[x])
                {
                        kek[{i,x}]=prefT(i);
                }
        }
        for (int p=1;p<=n;p++)
        {
                int i=idb[a[p]];
                if (i==0)
                        continue;
                ll x=sol[i-1]+neg(ant[i-1]+1,p-1)+poz(ant[i-1]+1,p-1,b[i-1]+1);
                ll y=sol[i]+neg(ant[i]+1,p)+poz(ant[i]+1,p,b[i]+1);
                sol[i]=min(x,y);
                ant[i]=p;
        }
        ll ans=sol[m];
        ans+=neg(ant[m]+1,n);
        ans+=poz(ant[m]+1,n,b[m]+1);
        if (ans>=INF/10)
                cout<<"NO\n";
        else
        {
                cout<<"YES\n";
                cout<<ans<<"\n";
        }
}