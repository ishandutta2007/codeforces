#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N=100000;

struct point
{
    int i;
    ld x,y;
};
point p1,p2,gu;
int n;
point ve[N+5];
point v1[N+5],v2[N+5];

ld dist(point a,point b)
{
    ld dif_x=a.x-b.x;
    ld dif_y=a.y-b.y;
    dif_x*=dif_x;
    dif_y*=dif_y;
    return (ld)sqrt(dif_x+dif_y);
}

ld val1(point a)
{
    return dist(p1,a)+dist(a,gu);
}

ld val2(point a)
{
    return dist(p2,a)+dist(a,gu);
}

bool cmp1(point a,point b)
{
    return val1(a)-2*dist(gu,a)<val1(b)-2*dist(gu,b);
}
bool cmp2(point a,point b)
{
    return val2(a)-2*dist(gu,a)<val2(b)-2*dist(gu,b);
}

void read(point *a)
{
    cin>>(a->x)>>(a->y);
}
ld best=0,start=0;

ld mi,mi2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read(&p1);
    read(&p2);
    read(&gu);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ve[i].i=i;
        read(&ve[i]);
        v1[i]=v2[i]=ve[i];
    }
    sort(v1+1,v1+n+1,cmp1);
    sort(v2+1,v2+n+1,cmp2);
    for(int i=1;i<=n;i++)
    {
        start+=2*dist(gu,ve[i]);
    }
    /// iau numai p1
    best=start-2*dist(gu,v1[1])+val1(v1[1]);
    /// iau numai p2
    best=min(best,start-2*dist(gu,v2[1])+val2(v2[1]));
    /// iau din ambele
    for(int i=1;i<=min(n,3);i++)
        for(int j=1;j<=min(n,3);j++)
        {
            if(v1[i].i==v2[j].i)
                continue;
            ///int a=v1[i].i;
            ///int b=v2[j].i
            ld score=start-2*dist(gu,v1[i])-2*dist(gu,v2[j])+val1(v1[i])+val2(v2[j]);
            best=min(best,score);
        }
    cout<<fixed<<setprecision(20)<<best<<"\n";
    return 0;
}
/**
**/