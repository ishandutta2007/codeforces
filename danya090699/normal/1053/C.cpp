#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, mod=1e9+7, inf=1e9+10;
int po[sz], we[sz], dot[3][sz*4];
void recalc(int i, int nu)
{
    dot[i][nu]=dot[i][nu*2]+dot[i][nu*2+1];
    if(i) dot[i][nu]%=mod;
}
void build(int i, int nu, int l, int r)
{
    if(l==r)
    {
        if(i==0) dot[i][nu]=we[l];
        if(i==1) dot[i][nu]=(((inf+l)-po[l])*we[l])%mod;
        if(i==2) dot[i][nu]=((po[l]-(l-inf))*we[l])%mod;
    }
    else
    {
        int mid=(l+r)>>1;
        build(i, nu*2, l, mid);
        build(i, nu*2+1, mid+1, r);
        recalc(i, nu);
    }
}
int p;
void cha(int i, int nu, int l, int r)
{
    if(l==r)
    {
        if(i==0) dot[i][nu]=we[l];
        if(i==1) dot[i][nu]=(((inf+l)-po[l])*we[l])%mod;
        if(i==2) dot[i][nu]=((po[l]-(l-inf))*we[l])%mod;
    }
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(i, nu*2, l, mid);
        else cha(i, nu*2+1, mid+1, r);
        recalc(i, nu);
    }
}
int lg, rg;
int que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[i][nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        int re=que(i, nu*2, l, mid)+que(i, nu*2+1, mid+1, r);
        if(i) re%=mod;
        return re;
    }
}
int cu, su;
int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if((cu+dot[0][nu])*2<=su)
        {
            cu+=dot[0][nu];
            return -1;
        }
        else
        {
            if(l==r) return l;
            else
            {
                int mid=(l+r)>>1;
                if((cu+dot[0][nu*2])*2<=su)
                {
                    cu+=dot[0][nu*2];
                    return que2(nu*2+1, mid+1, r);
                }
                else return que2(nu*2, l, mid);
            }
        }
    }
    else if(l>rg or r<lg) return -1;
    else
    {
        int mid=(l+r)>>1;
        int re=que2(nu*2, l, mid);
        if(re!=-1) return re;
        return que2(nu*2+1, mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++) scanf("%lld", &po[a]);
    for(int a=0; a<n; a++) scanf("%lld", &we[a]);
    for(int i=0; i<3; i++) build(i, 1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ch1, ch2;
        scanf("%lld%lld", &ch1, &ch2);
        if(ch1<0)
        {
            p=(-ch1)-1;
            we[p]=ch2;
            for(int i=0; i<3; i++) cha(i, 1, 0, n-1);
        }
        else
        {
            int l=ch1-1, r=ch2-1;
            lg=l, rg=r, su=que(0, 1, 0, n-1), cu=0;
            int mid=que2(1, 0, n-1), an=0;
            if(mid>l)
            {
                lg=l, rg=mid-1;
                int q=que(0, 1, 0, n-1)%mod;
                int s=que(1, 1, 0, n-1);
                int add=(mid+inf)-po[mid];
                s-=(q*add)%mod;
                if(s<0) s+=mod;
                an=(an+s)%mod;
            }
            if(mid<r)
            {
                lg=mid+1, rg=r;
                int q=que(0, 1, 0, n-1)%mod;
                int s=que(2, 1, 0, n-1);
                int add=po[mid]-(mid-inf);
                s-=(q*add)%mod;
                if(s<0) s+=mod;
                an=(an+s)%mod;
            }
            printf("%lld\n", an);
        }
    }
}