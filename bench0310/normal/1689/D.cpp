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
        int n,m;
        cin >> n >> m;
        const int inf=(1<<30);
        int lx=inf,rx=-inf,ly=inf,ry=-inf;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin >> s;
            for(int j=1;j<=m;j++)
            {
                if(s[j-1]=='B')
                {
                    lx=min(lx,i+j);
                    rx=max(rx,i+j);
                    ly=min(ly,i-j);
                    ry=max(ry,i-j);
                }
            }
        }
        int x=midpoint(lx,rx);
        int y=midpoint(ly,ry);
        if((x+y)&1)
        {
            if((rx-lx)&1) x++;
            else if((ry-ly)&1) y++;
            else if(rx-lx<=ry-ly) x++;
            else y++;
        }
        cout << (x+y)/2 << " " << (x-y)/2 << "\n";
    }
    return 0;
}