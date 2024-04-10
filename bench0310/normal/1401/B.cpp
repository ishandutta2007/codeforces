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
        int x0,x1,x2,y0,y1,y2;
        cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
        int z=min(x2,y1);
        int res=2*z;
        x2-=z;
        y1-=z;
        if(x2==0) res-=2*max(0,y2-x0);
        else res-=2*max(0,x1-y0);
        cout << res << "\n";
    }
    return 0;
}