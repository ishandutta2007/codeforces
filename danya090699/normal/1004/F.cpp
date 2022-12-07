#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, m, x;
int ar[sz];
long long su[sz*4];
pair <int, int> ls[sz*4][22], rs[sz*4][22];
set <int> se[21];
long long cou(int nu, int l, int r)
{
    long long an=0;
    int yk=0, lv=(1<<21)-1, rv=0;
    for(int a=1; a<22; a++)
    {
        lv-=(1<<(ls[nu][a-1].second));
        int ll=ls[nu][a-1].first+1, rr=ls[nu][a].first;
        int l1=max(l, ll), r1=min(r, rr);
        while((lv|rv)<x)
        {
            yk++, rv+=(1<<rs[nu][yk].second);
        }
        if(l1<=r1 and rs[nu][yk].first<=r)
        {
            an+=1ll*(r1-l1+1)*(r-rs[nu][yk].first+1);
        }
    }
    return an;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(ar[l]>=x) su[nu]=1;
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);

        for(int i=0; i<=20; i++)
        {
            auto it=se[i].upper_bound(mid);
            rs[nu][i].first=(*it);
            rs[nu][i].second=i;
            it--;
            ls[nu][i].first=(*it);
            ls[nu][i].second=i;
        }
        rs[nu][21]=make_pair(mid+1, -1);
        ls[nu][21]=make_pair(mid, 1e9);
        sort(ls[nu], ls[nu]+22);
        sort(rs[nu], rs[nu]+22);

        su[nu]=su[nu*2]+su[nu*2+1]+cou(nu, l, r);
    }
}
int p, ln[21], rn[21];
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        if(ar[p]>=x) su[nu]=1;
        else su[nu]=0;
    }
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);

        for(int a=0; a<22; a++)
        {
                if(p<=mid)
                {
                    int i=ls[nu][a].second;
                    if(i>=0 and i<=20)
                    {
                        if(ls[nu][a].first==p) ls[nu][a].first=ln[i];
                        if(ar[p]&(1<<i)) ls[nu][a].first=max(ls[nu][a].first, p);
                    }
                }
                else
                {
                    int i=rs[nu][a].second;
                    if(i>=0 and i<=20)
                    {
                        if(rs[nu][a].first==p) rs[nu][a].first=rn[i];
                        if(ar[p]&(1<<i)) rs[nu][a].first=min(rs[nu][a].first, p);
                    }
                }
        }
        sort(ls[nu], ls[nu]+22);
        sort(rs[nu], rs[nu]+22);

        su[nu]=su[nu*2]+su[nu*2+1]+cou(nu, l, r);
    }
}
int lg, rg;
long long que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return su[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return cou(nu, max(l, lg), min(r, rg))+que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>x;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        for(int i=0; i<20; i++) if(ar[a]&(1<<i)) se[i].insert(a);
    }
    for(int a=0; a<=20; a++)
    {
        se[a].insert(-1), se[a].insert(n);
    }
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int i, va;
            scanf("%d%d", &i, &va);
            i--;
            ar[i]=va;
            for(int b=0; b<=20; b++) se[b].erase(i);
            for(int b=0; b<=20; b++)
            {
                auto it=se[b].upper_bound(i);
                rn[b]=(*it);
                it--;
                ln[b]=(*it);
            }
            for(int b=0; b<20; b++) if(ar[i]&(1<<b)) se[b].insert(i);
            p=i, cha(1, 0, n-1);
        }
        else
        {
            scanf("%d%d", &lg, &rg);
            lg--, rg--;
            long long re=que(1, 0, n-1);
            printf("%lld\n", re);
        }
    }
}