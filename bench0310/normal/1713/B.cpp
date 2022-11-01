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
        vector<array<int,2>> a(n);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            a[i-1]={x,i};
        }
        ranges::sort(a,greater<>());
        int l=n,r=1;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            l=min(l,a[i][1]);
            r=max(r,a[i][1]);
            if(i+1<n&&a[i][0]>a[i+1][0]) ok&=(r-l+1==i+1);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}