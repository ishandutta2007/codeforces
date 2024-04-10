#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, bl=100, inf=4e18;
vector <int> sv[sz];
int tin[sz], si[sz], timer=0, A[sz], B[sz];
int ar[sz], add[sz], yk[sz], mi[sz];
void dfs(int v)
{
    tin[v]=timer++, si[v]=1, ar[tin[v]]=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        A[ne]+=A[v], B[ne]+=B[v], dfs(ne), si[v]+=si[ne];
    }
}
struct el
{
    int k, b, l;
};
vector <el> hull[sz];
void push(vector <el> &hull, int k, int b)
{
    while(hull.size())
    {
        int k2=hull.back().k, b2=hull.back().b, l2=hull.back().l;
        if(k2==k)
        {
            if(b>b2) hull.pop_back();
            else break;
        }
        else
        {
            int l;
            if(b<=b2) l=(b2-b)/(k-k2)+1;
            else l=-((b-b2)/(k-k2));
            if(l<=l2) hull.pop_back();
            else
            {
                hull.push_back({k, b, l});
                break;
            }
        }
    }
    if(hull.size()==0) hull.push_back({k, b, -inf});
}
void build(int l, int r)
{
    mi[l]=inf;
    for(int a=r; a>=l; a--)
    {
        int i=ar[a];
        if(A[i]<0)
        {
            push(hull[l], -abs(B[i]), abs(A[i]*B[i]));
            mi[l]=min(mi[l], -A[i]);
        }
    }
    for(int a=l; a<=r; a++)
    {
        int i=ar[a];
        if(A[i]>=0)
        {
            push(hull[l], abs(B[i]), abs(A[i]*B[i]));
        }
    }
    yk[l]=0;
    while(yk[l]+1<hull[l].size() and hull[l][yk[l]+1].l<=0) yk[l]++;
}
bool comp(int a, int b){return abs(B[a])<abs(B[b]);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%lld", &pr);
        pr--;
        sv[pr].push_back(a);
    }
    for(int a=0; a<n; a++) scanf("%lld", &A[a]);
    for(int a=0; a<n; a++) scanf("%lld", &B[a]);
    dfs(0);
    for(int a=0; a<n; a+=bl)
    {
        int r=min(a+bl, n);
        sort(ar+a, ar+r, comp);
        build(a, r-1);
    }
    for(int a=0; a<q; a++)
    {
        int ty, v;
        scanf("%lld%lld", &ty, &v);
        v--;
        int lg=tin[v], rg=lg+si[v]-1;
        if(ty==1)
        {
            int x;
            scanf("%lld", &x);
            for(int l=0; l<n; l+=bl)
            {
                int r=min(l+bl-1, n-1);
                if(!(l>rg or r<lg))
                {
                    if(l>=lg and r<=rg and mi[l]>=x)
                    {
                        add[l]+=x, mi[l]-=x;
                        while(yk[l]+1<hull[l].size() and hull[l][yk[l]+1].l<=add[l]) yk[l]++;
                    }
                    else
                    {
                        hull[l].clear();
                        for(int a=l; a<=r; a++)
                        {
                            int v=ar[a];
                            A[v]+=add[l];
                            if(tin[v]>=lg and tin[v]<=rg) A[v]+=x;
                        }
                        add[l]=0;
                        build(l, r);
                    }
                }
            }
        }
        else
        {
            int an=0;
            for(int l=0; l<n; l+=bl)
            {
                int r=min(l+bl-1, n-1);
                if(!(l>rg or r<lg))
                {
                    if(l>=lg and r<=rg)
                    {
                        el be=hull[l][yk[l]];
                        an=max(an, be.k*add[l]+be.b);
                    }
                    else
                    {
                        for(int a=l; a<=r; a++)
                        {
                            int v=ar[a];
                            if(tin[v]>=lg and tin[v]<=rg)
                            {
                                an=max(an, abs((A[v]+add[l])*B[v]));
                            }
                        }
                    }
                }
            }
            printf("%lld\n", an);
        }
    }
}