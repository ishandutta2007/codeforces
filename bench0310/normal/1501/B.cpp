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
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1,0);
        int t=0;
        for(int i=n;i>=1;i--)
        {
            t=max(t-1,a[i]);
            b[i]=(t>0);
        }
        for(int i=1;i<=n;i++) cout << b[i] << " \n"[i==n];
    }
    return 0;
}