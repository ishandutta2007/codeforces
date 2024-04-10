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
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        ranges::sort(a);
        int res=a[0];
        for(int i=0;i+1<n;i++) res=max(res,a[i+1]-a[i]);
        cout << res << "\n";
    }
    return 0;
}