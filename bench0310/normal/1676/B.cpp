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
        vector<int> a(n+1,0);
        int m=(1<<30);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=min(m,a[i]);
        }
        int res=0;
        for(int i=1;i<=n;i++) res+=(a[i]-m);
        cout << res << "\n";
    }
    return 0;
}