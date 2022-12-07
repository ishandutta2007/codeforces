#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e6;
vector <int> sp[2];
int an[sz], vx[2], vy[2];
bool ins(int i, int x, int y, int nu)
{
    int vx1=vx[i]+x, vy1=vy[i]+y, vx2=vx[i]-x, vy2=vy[i]-y;
    if((1ll*vx1*vx1+1ll*vy1*vy1)<=1ll*inf*inf)
    {
        an[nu]=0, sp[i].push_back(nu);
        vx[i]=vx1, vy[i]=vy1;
        return true;
    }
    else if((1ll*vx2*vx2+1ll*vy2*vy2)<=1ll*inf*inf)
    {
        an[nu]=1, sp[i].push_back(nu);
        vx[i]=vx2, vy[i]=vy2;
        return true;
    }
    else return false;
}
void merge()
{
    int i1=0, i2=1;
    if(sp[0].size()<sp[1].size()) swap(i1, i2);
    int vx1=vx[i1]+vx[i2], vy1=vy[i1]+vy[i2], vx2=vx[i1]-vx[i2], vy2=vy[i1]-vy[i2], k=0;
    if((1ll*vx1*vx1+1ll*vy1*vy1)>(1ll*vx2*vx2+1ll*vy2*vy2)) k=1;
    if(k==0)
    {
        vx[i1]=vx1, vy[i1]=vy1;
    }
    else
    {
        vx[i1]=vx2, vy[i1]=vy2;
    }
    for(int a=0; a<sp[i2].size(); a++)
    {
        sp[i1].push_back(sp[i2][a]);
        an[sp[i2][a]]^=k;
    }
    sp[i2].clear(), vx[i2]=0, vy[i2]=0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(!ins(0, x, y, a))
        {
            if(!ins(1, x, y, a))
            {
                merge();
                if(sp[0].size()==0) ins(0, x, y, a);
                else ins(1, x, y, a);
            }
        }
    }
    merge();
    for(int a=0; a<n; a++)
    {
        if(an[a]) printf("-1 ");
        else printf("1 ");
    }
}