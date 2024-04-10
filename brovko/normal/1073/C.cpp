#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int n, x, y, px[200005], py[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    cin >> x >> y;
    if(abs(x)+abs(y)>n || abs(x+y+n)%2!=0)
    {
        cout << -1;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
            px[i+1]=px[i]-1;
        if(s[i]=='R')
            px[i+1]=px[i]+1;
        if(s[i]=='U')
            py[i+1]=py[i]+1;
        if(s[i]=='D')
            py[i+1]=py[i]-1;

        if(s[i]=='R' || s[i]=='L')
            py[i+1]=py[i];
        if(s[i]=='U' || s[i]=='D')
            px[i+1]=px[i];
    }

    if(px[n]==x && py[n]==y)
    {
        cout << 0;
        return 0;
    }


    x-=px[n];
    y-=py[n];

    int d=1e9;

    //cout << x-px[4]+px[3] << ' ' << y-py[4]+py[3] << ' ' << x << ' ' << y << endl;

    for(int i=0;i<n;i++)
        {
            int j=min(i+d-2, n-1);
            int f=1;
            while(f)
            {
                int x1=x+px[j+1]-px[i];
                int y1=y+py[j+1]-py[i];
                if(abs(x1)+abs(y1)<=j-i+1)
                    d=j-i+1;
                else f=0;
                j--;
            }
        }
    cout << d;
}