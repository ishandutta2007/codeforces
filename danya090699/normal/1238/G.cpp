#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, inf=2e9;
struct el
{
    int t, in, a, b;
};
bool comp(el a, el b){return a.t<b.t;}
el ar[sz];

bool comp2(int a, int b){return ar[a].b<ar[b].b;}

int n, m, c, cu, dot[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=min(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void build(int nu, int l, int r)
{
    add[nu]=0;
    if(l==r) dot[nu]=ar[l].t+c-cu;
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int p, va;
int que(int nu, int l, int r)
{
    if(l>=p) return dot[nu]+add[nu];
    else if(r<p) return inf;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        int re=min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return re;
    }
}
void cha(int nu, int l, int r)
{
    if(l>=p) add[nu]+=va;
    else if(r>=p)
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int qq;
    cin>>qq;
    while(qq)
    {
        qq--;
        scanf("%d%d%d%d", &n, &m, &c, &cu);
        for(int a=0; a<n; a++)
        {
            scanf("%d%d%d", &ar[a].t, &ar[a].a, &ar[a].b);
        }
        sort(ar, ar+n, comp);
        ar[n].t=m;
        multiset <int, bool(*)(int, int)> se(&comp2);
        long long an=0;
        build(1, 0, n);
        for(int a=0; a<=n; a++)
        {
            while(cu<ar[a].t)
            {
                if(se.size())
                {
                    p=*se.begin();

                    int ma=que(1, 0, n), q=min(ar[p].a, min(ar[a].t-cu, ma));
                    an+=1ll*ar[p].b*q;
                    cu+=q, ar[p].a-=q, va=-q, cha(1, 0, n);
                    if(q==ma or ar[p].a==0) se.erase(se.begin());
                }
                else break;
            }
            if(cu<ar[a].t)
            {
                an=-1;
                break;
            }
            se.insert(a);
        }
        printf("%lld\n", an);
    }
}