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
        vector<int> a(n);
        for(int &x:a) cin >> x;
        int mn=a[0],mx=a[0];
        for(int x:a)
        {
            mn=min(mn,x);
            mx=max(mx,x);
        }
        int res=0;
        res=max(res,mx-a[0]);
        res=max(res,a[n-1]-mn);
        for(int i=0;i<n;i++) res=max(res,a[i]-a[(i+1)%n]);
        cout << res << "\n";
    }
    return 0;
}