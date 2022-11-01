#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> s(n+1,0);
        for(int i=1;i<=n;i++) cin >> s[i];
        vector<int> f(n+1,0);
        for(int i=1;i<=n;i++) cin >> f[i];
        int t=0;
        for(int i=1;i<=n;i++)
        {
            t=max(t,s[i]);
            cout << f[i]-t << " \n"[i==n];
            t=f[i];
        }
    }
    return 0;
}