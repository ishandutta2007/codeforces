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
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
        vector<int> tm(n+1,0);
        for(int i=1;i<=n;i++) cin >> tm[i];
        int t=0;
        for(int i=1;i<=n;i++)
        {
            t+=(a[i]-b[i-1]+tm[i]);
            if(i<n) t+=max((b[i]-a[i]+1)/2,b[i]-t);
        }
        cout << t << "\n";
    }
    return 0;
}