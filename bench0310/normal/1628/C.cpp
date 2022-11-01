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
        vector a(n,vector(n,int(0)));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
        auto go=[&]()->int
        {
            int r=0,c=0;
            auto mv=[&](int cnt)->bool
            {
                while(cnt--)
                {
                    if(r<n-1) r++;
                    else if(c<n-1) c++;
                    else return 0;
                }
                return 1;
            };
            int x=a[0][0];
            while(mv(4))
            {
                int tr=r;
                int tc=c;
                auto in=[&]()->bool{return (0<=tr&&tr<n&&0<=tc&&tc<n);};
                while(in())
                {
                    x^=a[tr][tc];
                    tr-=2;
                    tc+=2;
                }
            }
            return x;
        };
        int res=go();
        for(int i=0;i<n;i++) ranges::reverse(a[i]);
        res^=go();
        cout << res << "\n";
    }
    return 0;
}