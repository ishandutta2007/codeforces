#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=200, bl=510;
int n, m;
int q[sz2][sz], fi[sz2][sz], la[sz2][sz], to[sz], ma[sz2], add[sz2];
int l, r;
int ar[sz];
void ins(int nu, int p, int va)
{
    if(q[nu][p])
    {
        to[va]=fi[nu][p], fi[nu][p]=va;
    }
    else
    {
        fi[nu][p]=va, la[nu][p]=va, to[va]=-p;
    }
    q[nu][p]++;
}
void merge(int nu, int f, int t)
{
    if(q[nu][t]) to[la[nu][t]]=fi[nu][f];
    else fi[nu][t]=fi[nu][f];
    la[nu][t]=la[nu][f];
    to[la[nu][t]]=-t;
    q[nu][t]+=q[nu][f], q[nu][f]=0;
}
void cha(int nu, int x)
{
    for(int a=nu*bl+1; a<=min(n, (nu+1)*bl); a++) ar[a]=0;
    for(int a=nu*bl+1; a<=min(n, (nu+1)*bl); a++)
    {
        if(ar[a]==0)
        {
            int cu=a;
            while(cu>0) cu=to[cu];
            int p=-cu;
            cu=fi[nu][p];
            while(cu>0)
            {
                ar[cu]=p-add[nu];
                if(ar[cu]>x and cu>=l+1 and cu<=r+1) ar[cu]-=x;
                cu=to[cu];
            }
            q[nu][p]=0;
        }
    }
    for(int a=nu*bl+1; a<=min(n, (nu+1)*bl); a++) ins(nu, ar[a], a);
    add[nu]=0;
}
int que(int nu, int x)
{
    int re=0;
    if(x<=ma[nu])
    {
        x+=add[nu];
        if(q[nu][x])
        {
            int cu=fi[nu][x];
            while(cu>0)
            {
                if(cu>=l+1 and cu<=r+1) re++;
                cu=to[cu];
            }
        }
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=0; a<sz2; a++) for(int b=1; b<sz; b++) q[a][b]=0;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int nu=a/bl;
        ma[nu]=sz-1, add[nu]=0;
        ins(nu, x, a+1);
    }
    for(int a=0; a<m; a++)
    {
        int ty, x;
        scanf("%d%d%d%d", &ty, &l, &r, &x);
        l--, r--;
        int lg=l/bl, rg=r/bl;
        if(ty==1)
        {
            cha(lg, x);
            if(rg!=lg) cha(rg, x);
            for(int b=lg+1; b<rg; b++)
            {
                if(ma[b]>x)
                {
                    if(ma[b]-x<x)
                    {
                        for(int c=ma[b]+add[b]; c>x+add[b]; c--)
                        {
                            if(q[b][c]) merge(b, c, c-x);
                        }
                    }
                    else
                    {
                        for(int c=1+add[b]; c<=x+add[b]; c++)
                        {
                            if(q[b][c]) merge(b, c, c+x);
                        }
                        add[b]+=x;
                    }
                    ma[b]=max(ma[b]-x, x);
                }
            }
        }
        else
        {
            int an=que(lg, x);
            if(lg!=rg) an+=que(rg, x);
            for(int b=lg+1; b<rg; b++)
            {
                if(x<=ma[b]) an+=q[b][x+add[b]];
            }
            printf("%d\n", an);
        }
    }
}