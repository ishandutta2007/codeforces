#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y0 hodsifgsdh

using namespace std;
const int INF=4e16;

int x0, y0, ax, ay, bx, by, xs, ys, t, x[60], y[60], n, Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    x[0]=x0;
    y[0]=y0;
    n=1;
    while(x[n-1]<INF && y[n-1]<INF)
    {
        x[n]=x[n-1]*ax+bx;
        y[n]=y[n-1]*ay+by;
        n++;
    }
    for(int s=0;s<n;s++)
    {
        int ans=0;
        int curx=xs;
        int cury=ys;
        int curt=0;
        for(int i=s;i>=0;i--)
        {
            if(abs(curx-x[i])+abs(cury-y[i])+curt<=t)
            {
                curt+=abs(curx-x[i])+abs(cury-y[i]);
                curx=x[i];
                cury=y[i];
                ans++;
            }
        }
        for(int i=s+1;i<n;i++)
        {
            if(abs(curx-x[i])+abs(cury-y[i])+curt<=t)
            {
                curt+=abs(curx-x[i])+abs(cury-y[i]);
                curx=x[i];
                cury=y[i];
                ans++;
            }
        }
        Max=max(Max, ans);
    }
    cout << Max;
}