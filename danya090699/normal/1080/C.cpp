#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int n, int m, int co)
{
    return (n*m)/2+((n*m)%2)*co;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, m;
        cin>>n>>m;
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int x3, y3, x4, y4;
        cin>>x3>>y3>>x4>>y4;
        int bq=f(n, m, 0ll);
        bq-=f(x2-x1+1, y2-y1+1, (x1+y1)%2);
        int xl=max(x1, x3), xr=min(x2, x4), yl=max(y1, y3), yr=min(y2, y4);
        int s=0, wq=f(x4-x3+1, y4-y3+1, ((x3+y3)%2)^1);
        if(xl<=xr and yl<=yr)
        {
            s=(xr-xl+1)*(yr-yl+1);
            wq-=f(xr-xl+1, yr-yl+1, ((xl+yl)%2)^1);
        }
        bq+=wq+s;

        cout<<n*m-bq<<" "<<bq<<"\n";
    }
}