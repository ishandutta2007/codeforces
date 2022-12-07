#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, sz2=101, bsz=1e6, bl=400, blq=510;
char buf[bsz];
int byk;
void g_in(int &x)
{
    x=0;
    while(buf[byk]>='0' and buf[byk]<='9')
    {
        x=x*10+buf[byk]-'0', byk++;
    }
    byk++;
}
void nst()
{
    gets(buf), byk=0;
}
int n, m, l, r, x, y;
int ar[sz], to[blq][sz2], va[blq][sz2], va2[sz2], dp[sz2];
int cou(int v, int nu)
{
    if(to[nu][v]==0) dp[v]=va2[v];
    else dp[v]=cou(to[nu][v], nu);
    return dp[v];
}
void cha(int nu)
{
    for(int a=1; a<sz2; a++)
    {
        va2[a]=0, dp[a]=0;
    }
    for(int a=1; a<sz2; a++) va2[va[nu][a]]=a;
    for(int a=1; a<sz2; a++) cou(a, nu);
    for(int a=nu*bl; a<min((nu+1)*bl, n); a++)
    {
        ar[a]=dp[ar[a]];
        if(ar[a]==x and a>=l and a<=r) ar[a]=y;
    }
    for(int a=1; a<sz2; a++)
    {
        to[nu][a]=0, va[nu][a]=a;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    nst(), g_in(n), nst();
    for(int a=0; a<n; a++) g_in(ar[a]);
    nst(), g_in(m);
    for(int a=0; a*bl<n; a++)
    {
        for(int b=1; b<sz2; b++) va[a][b]=b;
    }
    for(int a=0; a<m; a++)
    {
        nst(), g_in(l), g_in(r), g_in(x), g_in(y);
        l--, r--;
        int lg=l/bl, rg=r/bl;
        cha(lg);
        if(rg!=lg) cha(rg);
        if(x!=y)
        {
            for(int b=lg+1; b<rg; b++)
            {
                int u=va[b][x], v=va[b][y];
                if(u!=0)
                {
                    if(v!=0) to[b][u]=v;
                    else va[b][y]=u;
                }
                va[b][x]=0;
            }
        }
    }
    x=0, y=0;
    for(int a=0; a*bl<n; a++) cha(a);
    for(int a=0; a<n; a++) printf("%d ", ar[a]);
}