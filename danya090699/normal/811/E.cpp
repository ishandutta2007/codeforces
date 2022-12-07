#include <bits/stdc++.h>
using namespace std;
const int sz=1e6;
char buf[sz];
int fyk;
void g_in(int &a)
{
    a=0;
    while(buf[fyk]>='0' and buf[fyk]<='9')
    {
        a=a*10+buf[fyk]-'0';
        fyk++;
    }
    fyk++;
}
void nst()
{
    fyk=0;
    gets(buf);
}
int n, m, q, **ar, cnu[40], cq, qq, ll, rr;
struct el
{
    int ls[10], rs[10], su;
};
el *dot;
vector <int> sv[40];
void dfs(int v)
{
    cnu[v]=cq, qq++;
    for(int a=0; a<sv[v].size(); a++) if(cnu[sv[v][a]]==-1) dfs(sv[v][a]);
}
el recalc(el &l, el &r, int lg)
{
    el re;
    if(l.su==-1) re=r;
    else if(r.su==-1) re=l;
    else
    {
        int an=l.su+r.su;
        for(int a=0; a<n; a++)
        {
            if(ar[a][lg]==ar[a][lg+1])
            {
                int v1=l.rs[a], v2=r.ls[a]+20;
                sv[v1].push_back(v2), sv[v2].push_back(v1);
            }
        }
        cq=0;
        for(int a=0; a<40; a++) cnu[a]=-1;
        for(int i=0; i<4; i++)
        {
            for(int a=0; a<n; a++)
            {
                int v;
                if(i==0) v=l.ls[a];
                if(i==1) v=r.rs[a];
                if(i==2) v=l.rs[a];
                if(i==3) v=r.ls[a];
                if(i==1 or i==3) v+=20;
                if(cnu[v]==-1)
                {
                    qq=0;
                    dfs(v);
                    an-=qq-1, cq++;
                }
                if(i==0) re.ls[a]=cnu[v];
                if(i==1) re.rs[a]=cnu[v];
                sv[v].clear();
            }
        }
        re.su=an;
    }
    return re;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        int cu=0, yk=0;
        while(yk<n)
        {
            int te=ar[yk][l];
            while(yk<n)
            {
                if(ar[yk][l]==te)
                {
                    dot[nu].ls[yk]=cu, dot[nu].rs[yk]=cu;
                    yk++;
                }
                else break;
            }
            cu++;
        }
        dot[nu].su=cu;
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=recalc(dot[nu*2], dot[nu*2+1], mid);
    }
}
el que(int nu, int l, int r)
{
    el an;
    if(l>=ll and r<=rr) an=dot[nu];
    else if(l>rr or r<ll) an.su=-1;
    else
    {
        int mid=(l+r)/2;
        el ls=que(nu*2, l, mid), rs=que(nu*2+1, mid+1, r);
        an=recalc(ls, rs, mid);
    }
    return an;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    nst(), g_in(n), g_in(m), g_in(q);
    ar=new int*[n];
    for(int a=0; a<n; a++)
    {
        ar[a]=new int[m];
        nst();
        for(int b=0; b<m; b++) g_in(ar[a][b]);
    }
    dot=new el[m*4];
    build(1, 0, m-1);
    for(int a=0; a<q; a++)
    {
        nst(), g_in(ll), g_in(rr);
        ll--, rr--;
        el an=que(1, 0, m-1);
        printf("%d\n", an.su);
    }
}