#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int n, ar[sz], q, si;
int dot[sz*4];
int lg, rg, x, ot[100][3];
void recalc(int nu)
{
    dot[nu]=(__gcd(dot[nu*2], dot[nu*2+1]));
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=x;
    else
    {
        int mid=(l+r)>>1;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        ot[si][0]=nu, ot[si][1]=l, ot[si][2]=r, si++;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    build(1, 0, n-1);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            scanf("%d%d%d", &lg, &rg, &x);
            lg--, rg--;
            si=0;
            que(1, 0, n-1);
            int q1=0, q2=0;
            for(int a=0; a<si; a++)
            {
                int nu=ot[a][0], l=ot[a][1], r=ot[a][2];
                if(dot[nu]%x==0) q1+=r-l+1;
                else
                {
                    while(l!=r)
                    {
                        int mid=(l+r)>>1;
                        if(dot[nu*2]%x==0)
                        {
                            q1+=mid-l+1, nu=nu*2+1, l=mid+1;
                        }
                        else
                        {
                            nu=nu*2, r=mid;
                        }
                    }
                    break;
                }
            }
            for(int a=si-1; a>=0; a--)
            {
                int nu=ot[a][0], l=ot[a][1], r=ot[a][2];
                if(dot[nu]%x==0) q2+=r-l+1;
                else
                {
                    while(l!=r)
                    {
                        int mid=(l+r)>>1;
                        if(dot[nu*2+1]%x==0)
                        {
                            q2+=r-mid, nu=nu*2, r=mid;
                        }
                        else
                        {
                            nu=nu*2+1, l=mid+1;
                        }
                    }
                    break;
                }
            }
            if(q1+q2+1>=(rg-lg+1)) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            scanf("%d%d", &lg, &x);
            lg--;
            cha(1, 0, n-1);
        }
    }
}