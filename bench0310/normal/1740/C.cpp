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
        ranges::sort(a);
        int res=0;
        auto go=[&]()
        {
            for(int i=2;i<n;i++) res=max(res,abs(a[i]-a[0])+abs(a[i]-a[i-1]));
        };
        go();
        ranges::reverse(a);
        go();
        cout << res << "\n";
    }
    return 0;
}