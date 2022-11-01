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
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        bool ok=1;
        for(int i=0;i<n-1;i++) ok&=(a[i+1]-a[i]<=1);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}