#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, x;
    cin>>n>>d>>x;
    int ar[n], lg[n], rg[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(a==0)
        {
            lg[a]=0, rg[a]=0;
        }
        else
        {
            lg[a]=lg[a-1], rg[a]=rg[a-1];
        }
        while(rg[a]+1<n)
        {
            if(de(rg[a]+1-a, d)<=n-(rg[a]+1)) rg[a]++;
            else break;
        }
        while(de(a-lg[a], d)>lg[a]+1) lg[a]++;
    }
    int l=-1, r=n;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int q[n], ykl=0, ykr=0, su=0, lq=de(n, 2)-mid, rq=n/2-mid;
        for(int a=0; a<n; a++) q[a]=ar[a];
        for(int a=0; a<=(n-1)/2; a++)
        {
            while(ykr<n)
            {
                if(lg[ykr]==a)
                {
                    su+=q[ykr], ykr++;
                }
                else break;
            }
            while(ykl<ykr)
            {
                if(rg[ykl]<a)
                {
                    su-=q[ykl], ykl++;
                }
                else break;
            }
            if(su>=x and lq>0)
            {
                int le=x;
                while(le)
                {
                    int qq=min(q[ykl], le);
                    q[ykl]-=qq, le-=qq;
                    if(q[ykl]==0) ykl++;
                }
                lq--, su-=x;
            }
        }
        ykl=n-1, ykr=n-1, su=0;
        for(int a=n-1; a>(n-1)/2; a--)
        {
            while(ykr>=0)
            {
                if(rg[ykr]==a)
                {
                    su+=q[ykr], ykr--;
                }
                else break;
            }
            while(ykl>ykr)
            {
                if(lg[ykl]>a)
                {
                    su-=q[ykl], ykl--;
                }
                else break;
            }
            if(su>=x and rq>0)
            {
                int le=x;
                while(le)
                {
                    int qq=min(q[ykl], le);
                    q[ykl]-=qq, le-=qq;
                    if(q[ykl]==0) ykl--;
                }
                rq--, su-=x;
            }
        }
        if(lq>0 or rq>0) l=mid;
        else r=mid;
    }
    cout<<r;
}