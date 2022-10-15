#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300000+5;

int n,m;

struct info
{
    int i;
    int a;
    int b;
};

bool cmp(info x,info y)
{
    return x.a-x.b<y.a-y.b;
}

info v[N];

ll ans[N];

int a[N],b[N];

int ra[N];
int rb[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].a>>v[i].b;
        ra[i]=v[i].a;
        rb[i]=v[i].b;
        v[i].i=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        ll co=min(v[x].a+v[y].b,v[y].a+v[x].b);
        ans[x]-=co;
        ans[y]-=co;
    }
    sort(v+1,v+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        a[v[i].i]=n-i;
        b[v[i].i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]+=a[i]*(long long)ra[i];
        ans[i]+=b[i]*(long long)rb[i];
    }
    ll sum=0LL;
    for(int i=1;i<=n;i++)
    {
        ans[v[i].i]+=sum;
        sum+=v[i].a;
    }
    sum=0LL;
    for(int i=n;i>=1;i--)
    {
        ans[v[i].i]+=sum;
        sum+=v[i].b;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
    for(int i=1;i<=n;i++)
    {
        cout<<v[i].i<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<b[i]<<" , "<<ans[i]<<"\n";
    }
    return 0;
}
/**



**/