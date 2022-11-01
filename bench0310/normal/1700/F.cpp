#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector a(n+2,array<ll,2>{0,0});
    int s=0;
    for(int d:{-1,1})
    {
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x;
                cin >> x;
                a[j][i]+=(d*x);
                s+=(d*x);
            }
        }
    }
    if(s==0)
    {
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            int d=0;
            auto &[x,y]=a[i];
            auto &[nx,ny]=a[i+1];
            ll t=min(abs(x),abs(y));
            if(x<0&&y>0) d=1;
            if(x>0&&y<0) d=-1;
            x+=(d*t);
            y-=(d*t);
            res+=abs(d*t);
            nx+=x;
            ny+=y;
            res+=(abs(x)+abs(y));
        }
        cout << res << "\n";
    }
    else cout << "-1\n";
    return 0;
}