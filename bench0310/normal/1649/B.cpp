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
        for(int i=1;i<=n;i++) cin >> a[i];
        ranges::sort(a);
        ll s=0;
        for(int i=1;i<=n-1;i++) s+=a[i];
        if(a[n]==0) cout << "0\n";
        else cout << max(ll(1),a[n]-s) << "\n";
    }
    return 0;
}