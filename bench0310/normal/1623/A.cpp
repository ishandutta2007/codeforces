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
        int n,m,r,c,x,y;
        cin >> n >> m >> r >> c >> x >> y;
        int res=n*m;
        auto upd=[&](int a){res=min(res,a);};
        if(r<=x) upd(x-r);
        else upd(n-r+n-x);
        if(c<=y) upd(y-c);
        else upd(m-c+m-y);
        cout << res << "\n";
    }
    return 0;
}