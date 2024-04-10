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
        int n;
        cin >> n;
        int lx=0,rx=0,ly=0,ry=0;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin >> x >> y;
            lx=min(lx,x);
            rx=max(rx,x);
            ly=min(ly,y);
            ry=max(ry,y);
        }
        cout << 2*(rx-lx+ry-ly) << "\n";
    }
    return 0;
}