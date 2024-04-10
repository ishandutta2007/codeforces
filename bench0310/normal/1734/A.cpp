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
        int res=numeric_limits<int>::max();
        for(int i=0;i+2<n;i++) res=min(res,a[i+2]-a[i]);
        cout << res << "\n";
    }
    return 0;
}