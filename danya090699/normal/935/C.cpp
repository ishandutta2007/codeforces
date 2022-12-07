#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int r, x1, y1, x2, y2;
    cin>>r>>x1>>y1>>x2>>y2;
    if((1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2))>1ll*r*r) cout<<x1<<" "<<y1<<" "<<r;
    else
    {
        if(x1==x2 and y1==y2) cout<<fixed<<setprecision(10)<<x1*1.0<<" "<<y1+(r/2.0)<<" "<<r/2.0;
        else
        {
            double d=sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
            double r2=(d+r)/2;
            double x3=x1+(x1-x2)*((r2-d)/d);
            double y3=y1+(y1-y2)*((r2-d)/d);
            cout<<fixed<<setprecision(10)<<x3<<" "<<y3<<" "<<r2;
        }
    }
}