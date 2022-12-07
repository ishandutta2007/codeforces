#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10;
pair <int, int> dot[sz*4];
int add[sz*4];
pair <int, int> get(int nu)
{
    return make_pair(dot[nu].first+add[nu], dot[nu].second);
}
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=max(get(nu*2), get(nu*2+1));
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]={l, l};
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int p, va;
void cha(int nu, int l, int r)
{
    if(l!=r)
    {
        push(nu);
        int mid=(l+r)>>1;
        if(p<mid) cha(nu*2, l, mid);
        else add[nu*2]+=va, cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
pair <int, int> que(int nu, int l, int r)
{
    if(l==r) return get(nu);
    else
    {
        push(nu);
        int mid=(l+r)>>1;
        pair <int, int> re;
        if(p<=mid) re=que(nu*2, l, mid);
        else re=max(get(nu*2), que(nu*2+1, mid+1, r));
        recalc(nu);
        return re;
    }
}
int fen[sz];
void cha2(int p, int va)
{
    while(p<sz)
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int que2(int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    int ar[q][2];
    build(1, 0, sz-1);
    for(int a=0; a<q; a++)
    {
        char ty[3];
        scanf("%s", ty);
        if(ty[0]=='+')
        {
            scanf("%lld%lld", &p, &va);
            cha(1, 0, sz-1), cha2(p, va);
            ar[a][0]=p, ar[a][1]=va;
        }
        if(ty[0]=='-')
        {
            int i;
            scanf("%lld", &i);
            i--, p=ar[i][0], va=-ar[i][1];
            cha(1, 0, sz-1), cha2(p, va);
        }
        if(ty[0]=='?')
        {
            scanf("%lld", &p);
            int l=que(1, 0, sz-1).second;
            printf("%lld\n", l+(que2(p)-que2(l-1))-p);
        }
    }
}