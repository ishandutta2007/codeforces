#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int w,h;
        cin >> w >> h;
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2=w-x2;
        y2=h-y2;
        int a,b;
        cin >> a >> b;
        if(!(a>x1+x2&&b>y1+y2))
        {
            int res=(1<<30);
            if(a<=x1+x2) res=min({res,a-x1,a-x2});
            if(b<=y1+y2) res=min({res,b-y1,b-y2});
            res=max(res,0);
            cout << res << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}