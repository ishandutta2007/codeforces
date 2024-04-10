#include <bits/stdc++.h>
#define iter map <int, vector <int> >::iterator
using namespace std;
int n, m, *dot, inf=2e9, bg=1e9, lg, rg, add, *ar;
bool er=0;
void push(int nu)
{
    dot[nu*2]=min(dot[nu*2], dot[nu]);
    dot[nu*2+1]=min(dot[nu*2+1], dot[nu]);
    dot[nu]=inf;
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu]=min(dot[nu], add);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
    }
}
int que(int nu, int l, int r)
{
    if(l==r) return dot[nu];
    else
    {
        int mid=(l+r)/2;
        push(nu);
        if(lg<=mid) return que(nu*2, l, mid);
        else return que(nu*2+1, mid+1, r);
    }
}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2], dot[nu*2+1]);
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha2(int nu, int l, int r)
{
    if(l==r) dot[nu]=add;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha2(nu*2, l, mid);
        else cha2(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        int an=max(que2(nu*2, l, mid), que2(nu*2+1, mid+1, r));
        recalc(nu);
        return an;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    dot=new int[n*4], ar=new int[n];
    int za[m][4];
    bool us[n];
    for(int a=0; a<n*4; a++) dot[a]=inf;
    for(int a=0; a<n; a++)
    {
        ar[a]=inf, us[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        scanf("%d", &za[a][0]);
        if(za[a][0]==1)
        {
            for(int b=1; b<4; b++) scanf("%d", &za[a][b]);
            za[a][1]--, za[a][2]--;
            lg=za[a][1], rg=za[a][2], add=za[a][3];
            cha(1, 0, n-1);
        }
        else
        {
            for(int b=1; b<3; b++) scanf("%d", &za[a][b]);
            za[a][1]--;
            lg=za[a][1];
            if(us[lg]==0)
            {
                ar[lg]=que(1, 0, n-1);
                us[lg]=1;
            }
        }
    }
    for(lg=0; lg<n; lg++)
    {
        if(us[lg]==0) ar[lg]=que(1, 0, n-1);
    }
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        if(za[a][0]==1)
        {
            lg=za[a][1], rg=za[a][2];
            int an=que2(1, 0, n-1);
            if(za[a][3]!=an) er=1;
        }
        else
        {
            lg=za[a][1], add=za[a][2];
            cha2(1, 0, n-1);
        }
    }
    if(er) printf("NO");
    else
    {
        printf("YES\n");
        map <int, vector <int> > ma;
        for(int a=0; a<n; a++)
        {
            ma[ar[a]].push_back(a);
            if(ar[a]==inf) ar[a]=bg;
        }
        if(ma[inf].size()>1)
        {
            int nu=ma[inf][0];
            ar[nu]=(1<<29)-1;
        }
        else
        {
            if(ma[inf].size()==0) ma.erase(inf);
            int an=0;
            for(iter it=ma.begin(); it!=ma.end(); it++)
            {
                int va=(*it).first, nu=(*it).second[0];
                if(va==inf)
                {
                    va=0;
                    for(int b=29; b>=0; b--)
                    {
                        int ne=(1<<b);
                        if((an&ne)==0)
                        {
                            if(va+ne<=bg) va+=ne;
                        }
                    }
                    an=(an|va);
                    ar[nu]=va;
                }
                else
                {
                    an=(an|va);
                    if((*it).second.size()>1)
                    {
                        for(int b=29; b>=1; b--)
                        {
                            int ne=(1<<b)-1;
                            if(va>=ne)
                            {
                                ar[nu]=ne, an=(an|ne);
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(int a=0; a<n; a++) printf("%d ", ar[a]);
    }
}