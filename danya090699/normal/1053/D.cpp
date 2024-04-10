#include <bits/stdc++.h>
using namespace std;
const int sz=2e6+10, inf=1e9, mod=1e9+7;
int n, m=0, di[sz], st[sz], be[sz], good=0, add=0, i=0, an=1;
bool us[sz];
vector <int> dot[sz];
vector <pair <int, int> > cha[sz];
int lg, rg, va;
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(va);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
    }
}
void ins2(int x)
{
    if(st[x])
    {
        x--;
        while(x>1)
        {
            int cu=di[x], q=0;
            while(x%cu==0) x/=cu, q++;
            if(q>st[cu])
            {
                cha[i].push_back(make_pair(cu, st[cu]));
                st[cu]=q;
                if(st[cu]==be[cu]) good++;
            }
            if(us[cu])
            {
                cha[i].push_back({cu, -1}), us[cu]=0, ins2(cu);
            }
        }
    }
    else
    {
        cha[i].push_back({x, 0}), st[x]=1;
        if(st[x]==be[x]) good++;
        cha[i].push_back({x, -1}), us[x]=1;
    }
}
void build(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++)
    {
        int x=dot[nu][a];
        ins2(x);
        i++;
    }
    if(l==r)
    {
        if(good==m) add=1;
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
    }
    for(int a=0; a<dot[nu].size(); a++)
    {
        i--;
        while(cha[i].size())
        {
            int cu=cha[i].back().first, q=cha[i].back().second;
            if(q==-1) us[cu]^=1;
            else
            {
                if(st[cu]==be[cu]) good--;
                st[cu]=q;
            }
            cha[i].pop_back();
        }
    }
}
main()
{
    for(int a=2; a<sz; a++) di[a]=inf;
    for(int a=2; a<sz; a++)
    {
        if(di[a]==inf) for(int b=a; b<sz; b+=a) di[b]=min(di[b], a);
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n, greater <int>());
    for(int a=0; a<n; a++)
    {
        int x=ar[a];

        lg=0, rg=a-1, va=x;
        if(lg<=rg) ins(1, 0, n-1);

        lg=a+1, rg=n-1, va=x;
        if(lg<=rg) ins(1, 0, n-1);

        if(be[x]) x--;
        while(x>1)
        {
            int cu=di[x], q=0;
            while(x%cu==0) x/=cu, q++;
            be[cu]=max(be[cu], q);
        }
    }
    for(int a=0; a<sz; a++)
    {
        if(be[a])
        {
            m++;
            for(int b=0; b<be[a]; b++) an=(1ll*an*a)%mod;
        }
    }
    build(1, 0, n-1);
    an=(an+add)%mod;
    cout<<an;
}