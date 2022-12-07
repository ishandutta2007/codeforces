#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10;
int su1[sz], su2[sz], su3[sz], ar1[sz], ar2[sz], ar3[sz], yk1=0, yk2=0, yk3=0;
int f(int se, int fi){return(su2[se]+su1[fi]);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    for(int a=0; a<sz; a++)
    {
        ar1[a]=0, ar2[a]=0, ar3[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int w, c;
        cin>>w>>c;
        if(w==1)
        {
            ar1[yk1]=c, yk1++;
        }
        if(w==2)
        {
            ar2[yk2]=c, yk2++;
        }
        if(w==3)
        {
            ar3[yk3]=c, yk3++;
        }
    }
    sort(ar1, ar1+sz, greater <int>());
    su1[0]=0;
    for(int a=1; a<sz; a++) su1[a]=su1[a-1]+ar1[a-1];
    sort(ar2, ar2+sz, greater <int>());
    su2[0]=0;
    for(int a=1; a<sz; a++) su2[a]=su2[a-1]+ar2[a-1];
    sort(ar3, ar3+sz, greater <int>());
    su3[0]=0;
    for(int a=1; a<sz; a++) su3[a]=su3[a-1]+ar3[a-1];
    for(int a=0; a*3<=m; a++)
    {
        int le=m-a*3, ma=(m-a*3)/2, cu=0;
        int l=0, r=ma;
        while(r-l>2)
        {
            int p1=(l+r)/2, p2=(l+r)/2+1;
            if(f(p1, le-p1*2)<f(p2, le-p2*2)) l=p1;
            else r=p2;
        }
        for(l; l<=r; l++) cu=max(cu, f(l, le-l*2));
        an=max(an, su3[a]+cu);
    }
    cout<<an;
}