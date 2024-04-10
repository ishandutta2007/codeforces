#include <bits/stdc++.h>
using namespace std;
const int sz=7e3+10;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d;
    cin>>n>>d;
    int ar[n], pr=-1e9, ykl=0, ykr=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    bitset <sz> l, r;
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int p;
        scanf("%d", &p);
        l<<=(p-pr);
        while(ykl<n and ar[ykl]<p)
        {
            if(p-ar[ykl]-1<sz) l[p-ar[ykl]-1]=1;
            ykl++;
        }
        r>>=(p-pr);
        while(ykr<n and ar[ykr]<p+sz)
        {
            if(ar[ykr]>=p) r[ar[ykr]-p]=1;
            ykr++;
        }
        pr=p;

        double an=atan2(1, min(l._Find_first(), r._Find_first()));

        bitset <sz> te=(l|(l<<1))&(r|(r<<1));

        an=max(an, atan2(1, te._Find_first())*2);

        printf("%.10f\n", an);
    }
}