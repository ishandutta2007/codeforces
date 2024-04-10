#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 oidhfdoif

using namespace std;

int q, h, c, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> h >> c >> t;
        int L=0;
        int R=1e9;
        while(R-L>1)
        {
            int M=(L+R)/2;
            ld x=(ld)(h*(M+1)+c*M)/(2*M+1);
            if(x<t)
                R=M;
            else L=M;
        }
        int ans=0;
        ld Min=1e9;
        ld x=(ld)(h*(L+1)+c*L)/(2*L+1);
        if(abs(t-x)<Min)
        {
            Min=abs(t-x);
            ans=2*L+1;
        }

        x=(ld)(h*(R+1)+c*R)/(2*R+1);
        if(abs(t-x)<Min)
        {
            Min=abs(t-x);
            ans=2*R+1;
        }

        x=(ld)(h+c)/2;
        if(abs(t-x)<Min)
        {
            Min=abs(t-x);
            ans=2;
        }
        cout << ans << endl;
    }
}