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
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        int res=(1<<30);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int c=0;
                for(int k=0;k<m;k++) c+=abs(s[i][k]-s[j][k]);
                res=min(res,c);
            }
        }
        cout << res << "\n";
    }
    return 0;
}