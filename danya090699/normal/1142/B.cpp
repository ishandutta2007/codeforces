#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], st;
int n, m, q, ar[sz];
void dfs(int v)
{
    st.push_back(v);
    if(st.size()>=n)
    {
        ar[v]=st[st.size()-n];
    }
    else ar[v]=-1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
    }
    st.pop_back();
}
int dot[sz*4];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=max(dot[nu*2], dot[nu*2+1]);
    }
}
int lg, rg;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return -1;
    else
    {
        int mid=(l+r)>>1;
        return max(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>q;
    int p[n], pr[n];
    for(int a=0; a<n; a++) scanf("%d", &p[a]), p[a]--;
    pr[p[0]]=p[n-1];
    for(int a=1; a<n; a++) pr[p[a]]=p[a-1];
    map <int, int> ma;
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if(ma.find(pr[x])!=ma.end())
        {
            sv[ma[pr[x]]].push_back(a);
        }
        ma[x]=a;
    }
    for(int a=0; a<m; a++) ar[a]=-2;
    for(int a=0; a<m; a++) if(ar[a]==-2) dfs(a);
    //for(int a=0; a<m; a++) cout<<ar[a]<<" ";
    build(1, 0, m-1);
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &lg, &rg);
        lg--, rg--;
        if(que(1, 0, m-1)>=lg) printf("1");
        else printf("0");
    }
}