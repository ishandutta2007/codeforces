#include <bits/stdc++.h>
using namespace std;
const int inf=3e5, sz=6e7;
int dot[sz][2], q=0;
void push(int nu)
{
    if(dot[nu][0]==-1)
    {
        int l=dot[nu][1], r=dot[nu][1]+1;
        dot[l][0]=-1, dot[r][0]=-1;
    }
}
void recalc(int nu, int lg, int rg)
{
    int l=dot[nu][1], r=dot[nu][1]+1, mid=(lg+rg)>>1;
    if(dot[l][0]==-1) dot[nu][0]=lg;
    else if(dot[l][0]<=inf) dot[nu][0]=dot[l][0];
    else if(dot[r][0]==-1) dot[nu][0]=mid+1;
    else dot[nu][0]=dot[r][0];
}
int bui(int nu)
{
    dot[q][0]=inf+1, dot[q][1]=-1, q++;
    if(nu!=-1) dot[q-1][0]=dot[nu][0], dot[q-1][1]=dot[nu][1];
    return q-1;
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(va) dot[nu][0]=-1;
        else dot[nu][0]=inf+1;
    }
    else if(!(l>rg or r<lg))
    {
        int ll=bui(dot[nu][1]), rr=bui(dot[nu][1]+1);
        dot[nu][1]=ll;
        push(nu);
        int mid=(l+r)>>1;
        cha(ll, l, mid);
        cha(rr, mid+1, r);
        recalc(nu, l, r);
    }
}
int p;
int que(int nu, int l, int r)
{
    if(l==r)
    {
        if(dot[nu][0]==l or dot[nu][0]==-1) return l;
        else return -1;
    }
    else
    {
        int ll=bui(dot[nu][1]), rr=bui(dot[nu][1]+1);
        dot[nu][1]=ll;
        push(nu);
        int mid=(l+r)>>1, rmi=dot[dot[nu][1]+1][0], re;
        if(rmi==-1) rmi=mid+1;
        if(rmi<=p) re=que(rr, mid+1, r);
        else re=que(ll, l, mid);
        recalc(nu, l, r);
        return re;
    }
}

struct el2
{
    int attack, health, d, died;
};
vector <el2> cr;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int ty, nu;
        scanf("%d", &ty);
        if(ty==1)
        {
            cr.push_back({0, q, 0, -1});
            bui(-1);
            int rt=bui(cr.back().health);
            lg=0, rg=0, va=1, cha(rt, 0, inf);
            cr.back().health=rt;
        }
        if(ty==2)
        {
            scanf("%d", &nu);
            nu--;
            cr[nu].attack++;
        }
        if(ty==3)
        {
            scanf("%d", &nu);
            nu--;
            cr[nu].d++;
        }
        if(ty==4)
        {
            scanf("%d", &nu);
            nu--;
            cr.push_back(cr[nu]);
            if(cr.back().died!=-1) cr.back().died=a+1;
        }
        if(ty==5)
        {
            int sp[2];
            scanf("%d%d", &sp[0], &sp[1]);
            sp[0]--, sp[1]--;
            if(cr[sp[0]].died==-1 and cr[sp[1]].died==-1)
            {
                for(int i=0; i<2; i++)
                {
                    int nu=sp[i];
                    int rt=bui(cr[nu].health);
                    p=cr[nu].d-cr[sp[i^1]].attack;
                    int re=que(rt, 0, inf);
                    if(re==-1) cr[nu].died=a+1;
                    else
                    {
                        rt=bui(cr[nu].health);
                        lg=re+1, rg=p, va=1;
                        if(lg<=rg) cha(rt, 0, inf);

                        rt=bui(rt);
                        lg=re, rg=re, va=0;
                        cha(rt, 0, inf);

                        cr[nu].health=rt;
                        if(dot[rt][0]>inf) cr[nu].died=a+1;
                    }
                }
            }
        }
    }
    cout<<cr.size()<<"\n";
    for(int a=0; a<cr.size(); a++) printf("%d ", cr[a].died);
}