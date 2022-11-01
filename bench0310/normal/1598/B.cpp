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
        vector<array<int,5>> v(n+1,{0,0,0,0,0});
        for(int i=1;i<=n;i++) for(int j=0;j<5;j++) cin >> v[i][j];
        bool res=0;
        for(int a=0;a<5;a++)
        {
            for(int b=a+1;b<5;b++)
            {
                int x=0,y=0;
                bool ok=1;
                for(int i=1;i<=n;i++)
                {
                    if(v[i][a]&&!v[i][b]) x++;
                    if(!v[i][a]&&v[i][b]) y++;
                    ok&=(v[i][a]||v[i][b]);
                }
                res|=(ok&&x<=n/2&&y<=n/2);
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}