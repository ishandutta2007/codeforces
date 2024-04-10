#include <bits/stdc++.h>
using namespace std;
const int sz=120000+10;
int mi[sz*4], q[sz*4], add[sz*4], add2[sz*4], lg, rg, va;
long long su[sz*4], an[sz];
vector <pair <int, int> > zap[sz];
void push(int nu)
{
    su[nu]+=1ll*q[nu]*add2[nu];
    if(mi[nu*2]+add[nu*2]==mi[nu]) add2[nu*2]+=add2[nu];
    if(mi[nu*2+1]+add[nu*2+1]==mi[nu]) add2[nu*2+1]+=add2[nu];
    add2[nu]=0;
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    mi[nu]=min(mi[nu*2]+add[nu*2], mi[nu*2+1]+add[nu*2+1]);
    q[nu]=0;
    if(mi[nu]==mi[nu*2]+add[nu*2]) q[nu]+=q[nu*2];
    if(mi[nu]==mi[nu*2+1]+add[nu*2+1]) q[nu]+=q[nu*2+1];
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void build(int nu, int l, int r)
{
    if(l==r) q[nu]=1;
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
long long que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return su[nu]+1ll*q[nu]*add2[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        long long re=que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
        recalc(nu);
        return re;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int q;
    cin>>q;
    vector <int> mi, ma;
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        zap[r].push_back(make_pair(l, a));
    }
    build(1, 0, n-1);
    for(int a=0; a<n; a++)
    {
        while(mi.size())
        {
            int i=mi.back();
            if(ar[a]<ar[i])
            {
                mi.pop_back();
                lg=0, rg=i, va=ar[i]-ar[a];
                if(mi.size()) lg=mi.back()+1;
                cha(1, 0, n-1);
            }
            else break;
        }
        mi.push_back(a);
        while(ma.size())
        {
            int i=ma.back();
            if(ar[a]>ar[i])
            {
                ma.pop_back();
                lg=0, rg=i, va=ar[a]-ar[i];
                if(ma.size()) lg=ma.back()+1;
                cha(1, 0, n-1);
            }
            else break;
        }
        ma.push_back(a);
        lg=a, rg=a, va=-(n-a);
        cha(1, 0, n-1);
        add2[1]++;
        for(int b=0; b<zap[a].size(); b++)
        {
            lg=zap[a][b].first, rg=a;
            int nu=zap[a][b].second;
            an[nu]=que(1, 0, n-1);
        }
    }
    for(int a=0; a<q; a++) printf("%lld\n", an[a]);
}