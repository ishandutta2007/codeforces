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
        auto q=[&](int r,int c,bool dig=0)->int
        {
            cout << (!dig?"SCAN":"DIG") << " " << r << " " << c << endl;
            int s;
            cin >> s;
            return s;
        };
        int one=(q(1,1)+4),two=(q(1,m)+2-2*m);
        int rsum=(one+two)/2;
        int csum=(one-two)/2;
        int rtmp=(q(rsum/2,1)+2);
        int rdif=(rtmp-csum);
        int ctmp=(q(1,csum/2)+2);
        int cdif=(ctmp-rsum);
        int r1=(rsum-rdif)/2;
        int r2=(rsum-r1);
        int c1=(csum-cdif)/2;
        int c2=(csum-c1);
        if(q(r1,c1,1)==1) q(r2,c2,1);
        else
        {
            q(r1,c2,1);
            q(r2,c1,1);
        }
    }
    return 0;
}