#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    set <int> r[n], c[m];
    for(int a=0; a<k; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        r[x].insert(y), c[y].insert(x);
    }
    int lx=0, rx=n, ly=0, ry=m, ty=0;
    long long lef=1ll*n*m-k;
    while(lx<rx and ly<ry)
    {
        if(ty==0)
        {
            auto it=r[lx].lower_bound(ly);
            if(it!=r[lx].end()) ry=min(ry, *it);
            lef-=ry-ly, lx++, ty=2;
        }
        else if(ty==1)
        {
            auto it=r[rx-1].lower_bound(ry);
            if(it!=r[rx-1].begin())
            {
                it--, ly=max(ly, (*it)+1);
            }
            lef-=ry-ly, rx--, ty=3;
        }
        else if(ty==2)
        {
            auto it=c[ry-1].lower_bound(lx);
            if(it!=c[ry-1].end()) rx=min(rx, *it);
            lef-=rx-lx, ry--, ty=1;
        }
        else if(ty==3)
        {
            auto it=c[ly].lower_bound(rx);
            if(it!=c[ly].begin())
            {
                it--, lx=max(lx, (*it)+1);
            }
            lef-=rx-lx, ly++, ty=0;
        }
    }
    if(lef) cout<<"No";
    else cout<<"Yes";
}