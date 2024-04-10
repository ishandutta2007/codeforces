#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, bl=2e3;
int ar[sz], zap[sz][3], an[sz], ar2[sz], q[sz], q2[sz];
void ins(int x)
{
    q2[q[x]]--, q[x]++, q2[q[x]]++;
}
void del(int x)
{
    q2[q[x]]--, q[x]--, q2[q[x]]++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]), ma[ar[a]]=0;
    }
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &zap[a][b]);
        zap[a][1]--;
        if(zap[a][0]==1) zap[a][2]--;
        else ma[zap[a][2]]=0;
    }
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        (*it).second=m, m++;
    }
    for(int a=0; a<n; a++) ar[a]=ma[ar[a]];
    for(int a=0; a<q; a++) if(zap[a][0]==2) zap[a][2]=ma[zap[a][2]];
    for(int a=0; a<=(n-1)/bl; a++)
    {
        for(int b=a; b<=(n-1)/bl; b++)
        {
            int lg=a*bl, rg=(b+1)*bl;
            for(int c=lg; c<rg; c++)
            {
                ar2[c]=ar[c], ins(ar2[c]);
            }
            for(int c=0; c<q; c++)
            {
                int ty=zap[c][0];
                if(ty==1)
                {
                    int l=zap[c][1], r=zap[c][2];
                    if(l/bl==a and r/bl==b)
                    {
                        for(int d=lg; d<l; d++) del(ar2[d]);
                        for(int d=rg-1; d>r; d--) del(ar2[d]);
                        for(int d=1; ; d++)
                        {
                            if(q2[d]==0)
                            {
                                an[c]=d;
                                break;
                            }
                        }
                        for(int d=lg; d<l; d++) ins(ar2[d]);
                        for(int d=rg-1; d>r; d--) ins(ar2[d]);
                    }
                }
                else
                {
                    int p=zap[c][1], x=zap[c][2];
                    if(p>=lg and p<rg)
                    {
                        del(ar2[p]), ar2[p]=x, ins(x);
                    }
                }
            }
            for(int c=lg; c<rg; c++) del(ar2[c]);
        }
    }
    for(int a=0; a<q; a++) if(an[a]) printf("%d\n", an[a]);
}