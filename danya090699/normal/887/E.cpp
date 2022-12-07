#include <bits/stdc++.h>
using namespace std;
double eps=1e-9;
bool s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return ((1ll*(x2-x1)*(y2+y1)+1ll*(x3-x2)*(y3+y2)+1ll*(x1-x3)*(y1+y3))>0);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int x1, y1, x2, y2, n;
    cin>>x1>>y1>>x2>>y2>>n;
    int vx=y2-y1, vy=-(x2-x1);
    double x3=(x1+x2)/2.0, y3=(y1+y2)/2.0, le=sqrt(1ll*vx*vx+1ll*vy*vy);
    vector < pair <double, int> > ve;
    double be=0;
    for(int a=0; a<n; a++)
    {
        int x, y, r1, k=-1;
        scanf("%d%d%d", &x, &y, &r1);
        if(s(x1, y1, x2, y2, x1+vx, y1+vy)!=s(x1, y1, x2, y2, x, y)) k=1;
        double lg, rg;
        double l=1e13*k, r;
        r=l*-1;
        for(int b=0; b<150; b++)
        {
            double mid=(l+r)/2;
            double kk=mid/le;
            double x4=x3+kk*vx, y4=y3+kk*vy;
            double r2=sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1)), di=sqrt((x4-x)*(x4-x)+(y4-y)*(y4-y));
            if(di>r2+r1) l=mid;
            else r=mid;
        }
        lg=r;
        l=1e13*k, r=l*-1;
        for(int b=0; b<150; b++)
        {
            double mid=(l+r)/2;
            double kk=mid/le;
            double x4=x3+kk*vx, y4=y3+kk*vy;
            double r2=sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1)), di=sqrt((x4-x)*(x4-x)+(y4-y)*(y4-y));
            if(di+r1>r2) l=mid;
            else r=mid;
        }
        rg=r;
        if(lg>rg) swap(lg, rg);
        if(lg<0 and rg>0) be=1e18;
        ve.push_back(make_pair(lg, 1)), ve.push_back(make_pair(rg, -1));
    }
    sort(ve.begin(), ve.end());
    int yk=0, q=0;
    while(yk<ve.size())
    {
        double cu=ve[yk].first, q1=0, q2=0;
        if(q<=0) be=min(be, abs(cu));
        while(yk<ve.size())
        {
            if(abs(ve[yk].first-cu)<eps)
            {
                if(ve[yk].second==1) q1++;
                else q2++;
                yk++;
            }
            else break;
        }
        q-=q2;
        if(q<=0) be=min(be, abs(cu));
        q+=q1;
    }
    double an=sqrt((le/2)*(le/2)+be*be);
    cout<<fixed<<setprecision(10)<<an;
}