#include <bits/stdc++.h>
using namespace std;
int q, n, *ar, *dot, lg, rg, add;
void ins(int nu, int l, int r)
{
    if(l==r) dot[nu]+=add;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) ins(nu*2, l, mid);
        else ins(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return (que(nu*2, l, mid)+que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>q;
    int so[q][3];
    set <int> se;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &so[a][0], &so[a][1]);
        if(so[a][0]==3) scanf("%d", &so[a][2]);
        else se.insert(so[a][1]);
    }
    n=se.size();
    ar=new int[n], dot=new int[n*4];
    int yk=0;
    for(set <int>::iterator it=se.begin(); it!=se.end(); it++)
    {
        ar[yk]=*it, yk++;
    }
    for(int a=0; a<n*4; a++) dot[a]=0;
    for(int a=0; a<q; a++)
    {
        int ty=so[a][0], p=so[a][1];
        if(ty==1)
        {
            lg=lower_bound(ar, ar+n, p)-ar;
            add=1;
            ins(1, 0, n-1);
        }
        if(ty==2)
        {
            lg=lower_bound(ar, ar+n, p)-ar;
            add=-1;
            ins(1, 0, n-1);
        }
        if(ty==3)
        {
            int l=so[a][2], bp[27], bl[27], cu=0, an=0;
            for(int b=0; b<27; b++)
            {
                bp[b]=p%2, bl[b]=l%2;
                p/=2, l/=2;
            }
            for(int b=26; b>=0; b--)
            {
                if(bl[b]==0) cu+=(1<<b)*bp[b];
                else
                {
                    int ll=cu+(1<<b)*bp[b], rr=ll+(1<<b);
                    lg=lower_bound(ar, ar+n, ll)-ar;
                    rg=lower_bound(ar, ar+n, rr)-ar;
                    if(rg>lg)
                    {
                        rg--;
                        an+=que(1, 0, n-1);
                    }
                    cu+=(1<<b)*(bp[b]^1);
                }
            }
            printf("%d\n", an);
        }
    }
}