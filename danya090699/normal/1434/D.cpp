#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int rt[2], di=0;
struct re
{
    int to, i, w;
};
vector <re> sv[sz];
pair <int, int> dfs(int v, int pr)
{
    pair <int, int> be = {0, v};
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to;
        if(ne!=pr)
        {
            pair <int, int> re=dfs(ne, v);
            if(be.first+re.first>di)
            {
                di=be.first+re.first, rt[0]=be.second, rt[1]=re.second;
            }
            be=max(be, re);
        }
    }
    be.first++;
    return be;
}

int L[2][sz], R[2][sz], c[2][sz], h[2][sz], timer;
int dfs2(int i, int v, int pr)
{
    int p=timer++;
    L[i][pr]=p;
    R[i][pr]=p;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to, nu=sv[v][a].i, w=sv[v][a].w;
        if(nu!=pr)
        {
            c[i][timer]=c[i][p]^w;
            h[i][timer]=h[i][p]+1;
            R[i][pr]+=dfs2(i, ne, nu);
        }
    }
    return R[i][pr]-p+1;
}

struct el
{
    bool add=0;
    int ma[2]={0, 0};
};
el dot[2][sz*4];

void push(int i, int nu)
{
    dot[i][nu*2].add^=dot[i][nu].add;
    dot[i][nu*2+1].add^=dot[i][nu].add;
    dot[i][nu].add=0;
}
void recalc(int i, int nu)
{
    for(int j=0; j<2; j++)
    {
        dot[i][nu].ma[j]=max(dot[i][nu*2].ma[j^dot[i][nu*2].add], dot[i][nu*2+1].ma[j^dot[i][nu*2+1].add]);
    }
}
void build(int i, int nu, int l, int r)
{
    if(l==r)
    {
        dot[i][nu].ma[c[i][l]]=h[i][l];
    }
    else
    {
        int mid=(l+r)>>1;
        build(i, nu*2, l, mid);
        build(i, nu*2+1, mid+1, r);
        recalc(i, nu);
    }
}
int lg, rg;
void cha(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[i][nu].add^=1;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(i, nu);
        cha(i, nu*2, l, mid);
        cha(i, nu*2+1, mid+1, r);
        recalc(i, nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[v].push_back({u, a, w});
        sv[u].push_back({v, a, w});
    }
    dfs(0, 0);
    for(int i=0; i<2; i++)
    {
        timer=0;
        dfs2(i, rt[i], 0);
        build(i, 1, 0, n-1);
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int nu, an=0;
        scanf("%d", &nu);
        for(int i=0; i<2; i++)
        {
            lg=L[i][nu], rg=R[i][nu];
            cha(i, 1, 0, n-1);
            an=max(an, dot[i][1].ma[0]);
        }
        printf("%d\n", an);
    }
}