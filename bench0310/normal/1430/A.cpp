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
        array<int,3> res={-1,-1,-1};
        for(int i=0;i<=5;i++)
        {
            for(int j=0;j<=2;j++)
            {
                int x=7*i+5*j;
                if(x<=n&&((n-x)%3)==0) res={(n-x)/3,j,i};
            }
        }
        if(res[0]!=-1) cout << res[0] << " " << res[1] << " " << res[2] << "\n";
        else cout << "-1\n";
    }
    return 0;
}