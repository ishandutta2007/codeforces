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
        vector<int> b(n);
        for(int &x:b) cin >> x;
        ranges::sort(a);
        ranges::sort(b);
        bool ok=1;
        for(int i=0;i<n;i++) ok&=(0<=b[i]-a[i]&&b[i]-a[i]<=1);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}