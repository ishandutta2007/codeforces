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
        vector<ll> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        int res=0;
        for(int l=1;l<=n;l++)
        {
            for(int r=l;r<=min(n,l+3);r++)
            {
                bool ok=1;
                for(int x=l;x<=r;x++) for(int y=x+1;y<=r;y++) for(int z=y+1;z<=r;z++) ok&=((!(b[x]<=b[y]&&b[y]<=b[z]))&&(!(b[x]>=b[y]&&b[y]>=b[z])));
                res+=ok;
            }
        }
        cout << res << "\n";
    }
    return 0;
}