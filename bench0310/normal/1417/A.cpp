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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int res=0;
        int m=k;
        for(int i=1;i<n;i++)
        {
            int x=(k-a[i])/a[0];
            res+=x;
            a[i]+=(a[0]*x);
            m=min(m,a[i]);
        }
        res+=(k-a[0])/m;
        cout << res << "\n";
    }
    return 0;
}