#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000+5;

int n,m;
int x[N],y[N],a[N];

int lft[N];
int t[N];

inline int dad(int a)
{
    if(t[a]==a)
    {
        return a;
    }
    else
    {
        return t[a]=dad(t[a]);
    }
}

inline void uni(int a,int b)
{
    a=dad(a); b=dad(b);
    lft[a]+=lft[b];
    t[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        t[i]=i;
        lft[i]=1;
    }
    for(int i=1;i<=m;i++) cin>>x[i]>>y[i]>>a[i];
    vector<int>id;
    for(int i=1;i<=m;i++) id.push_back(i);
    sort(id.begin(),id.end(),[] (int i,int j)
    {
        return a[i]>a[j];
    });
    ll ans=0LL;
    for(int i:id)
    {
        if(dad(x[i])==dad(y[i]))
        {
            if(lft[dad(x[i])]>0)
            {
                ans+=a[i];
                lft[dad(x[i])]--;
            }
        }
        else
        {
            if(lft[dad(x[i])]>0 || lft[dad(y[i])]>0)
            {
                ans+=a[i];
                uni(x[i],y[i]);
                lft[dad(x[i])]--;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}