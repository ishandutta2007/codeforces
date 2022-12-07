#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e3+10;
int su[sz][sz];
int n, m, q, lx, rx, ly, ry, mx, my, inf=1e9+10, an;
int f(int lx, int ly, int rx, int ry, int ty)
{
    int re=su[rx+1][ry+1]-su[rx+1][ly]-su[lx][ry+1]+su[lx][ly];
    if(ty) re=(rx-lx+1)*(ry-ly+1)-re;

    //cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<" "<<ty<<": "<<re<<"\n";

    return re;
}
void dfsy(int l, int r, int lx, int rx)
{
    if(!(l>ry or r<ly))
    {
        if(r-l+1==m)
        {
            l=max(l, ly), r=min(r, ry);
            int xty=lx/n, yty=l/m;
            an+=f(lx%n, l%m, rx%n, r%m, __builtin_popcountll(xty^yty)%2);
        }
        else if(l>=ly and r<=ry) an+=(r-l+1)*(rx-lx+1)/2;
        else
        {
            int mid=(l+r)>>1;
            dfsy(l, mid, lx, rx), dfsy(mid+1, r, lx, rx);
        }
    }
}
void dfsx(int l, int r)
{
    if(!(l>rx or r<lx))
    {
        //cout<<l<<" "<<r<<"\n";
        if(r-l+1==n)
        {
            //cout<<max(l, lx)<<" "<<min(r, rx)<<"\n";
            dfsy(0, my-1, max(l, lx), min(r, rx));
        }
        else if(l>=lx and r<=rx)
        {
            //cout<<"!";
            an+=(r-l+1)*(ry-ly+1)/2;
        }
        else
        {
            int mid=(l+r)>>1;
            dfsx(l, mid), dfsx(mid+1, r);
        }
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>q;
    mx=n, my=m;
    while(mx<inf) mx*=2;
    while(my<inf) my*=2;

    for(int a=0; a<n; a++)
    {
        char s[m+1];
        scanf("%s", s);
        for(int b=0; b<m; b++) su[a+1][b+1]=su[a+1][b]+su[a][b+1]-su[a][b]+(s[b]-'0');
    }

    for(int a=0; a<q; a++)
    {
        scanf("%lld%lld%lld%lld", &lx, &ly, &rx, &ry);
        lx--, rx--, ly--, ry--;
        an=0, dfsx(0, mx-1);
        printf("%lld\n", an);
    }
}