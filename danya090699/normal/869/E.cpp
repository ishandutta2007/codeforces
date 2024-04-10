#include <bits/stdc++.h>
#define iter map < pair < pair <int, int>, pair <int, int> >, long long >::iterator
using namespace std;
const int sz=5e3+10;
long long dot[sz][sz];
int n, m, qq;
int q=1, l[sz], r[sz], q2=1, l2[sz], r2[sz];
int lg, rg, lg2, rg2, num;
long long add, an;
void build(int nu, int ll, int rr)
{
    if(ll!=rr)
    {
        int mid=(ll+rr)>>1;
        l[nu]=q, r[nu]=q+1, q+=2;
        build(l[nu], ll, mid);
        build(r[nu], mid+1, rr);
    }
}
void build2(int nu, int ll, int rr)
{
    if(ll!=rr)
    {
        int mid=(ll+rr)>>1;
        l2[nu]=q2, r2[nu]=q2+1, q2+=2;
        build2(l2[nu], ll, mid);
        build2(r2[nu], mid+1, rr);
    }
}
void ins2(int nu, int ll, int rr)
{
    if(ll>=lg2 and rr<=rg2)
    {
        dot[num][nu]^=add;
    }
    else if(!(ll>rg2 or rr<lg2))
    {
        int mid=(ll+rr)>>1;
        ins2(l2[nu], ll, mid);
        ins2(r2[nu], mid+1, rr);
    }
}
void ins(int nu, int ll, int rr)
{

    if(ll>=lg and rr<=rg)
    {
        num=nu, ins2(0, 0, m-1);
    }
    else if(!(ll>rg or rr<lg))
    {
        int mid=(ll+rr)>>1;
        ins(l[nu], ll, mid);
        ins(r[nu], mid+1, rr);
    }
}
void que2(int nu, int ll, int rr)
{
    an^=dot[num][nu];
    if(ll!=rr)
    {
        int mid=(ll+rr)>>1;
        if(lg2<=mid) que2(l2[nu], ll, mid);
        else que2(r2[nu], mid+1, rr);
    }
}
void que(int nu, int ll, int rr)
{
    num=nu, que2(0, 0, m-1);
    if(ll!=rr)
    {
        int mid=(ll+rr)>>1;
        if(lg<=mid) que(l[nu], ll, mid);
        else que(r[nu], mid+1, rr);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>qq;
    build(0, 0, n-1);
    build2(0, 0, m-1);
    map < pair < pair <int, int>, pair <int, int> >, long long > ma;
    for(int a=0; a<qq; a++)
    {

        int ty;
        scanf("%d%d%d%d%d", &ty, &lg, &lg2, &rg, &rg2);
        lg--, rg--, lg2--, rg2--;
        if(ty==1)
        {
            add=1ll*rand()*rand()*rand()*rand();
            ma[make_pair(make_pair(lg, lg2), make_pair(rg, rg2))]=add;
            ins(0, 0, n-1);
        }
        if(ty==2)
        {
            iter it=ma.find(make_pair(make_pair(lg, lg2), make_pair(rg, rg2)));
            add=(*it).second;
            ma.erase(it);
            ins(0, 0, n-1);
        }
        if(ty==3)
        {

            long long an1, an2;
            an=0;
            que(0, 0, n-1), an1=an;
            an=0, lg=rg, lg2=rg2;
            que(0, 0, n-1), an2=an;
            if(an1==an2) printf("Yes\n");
            else printf("No\n");
        }
    }
}