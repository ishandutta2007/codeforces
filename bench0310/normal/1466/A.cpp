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
        set<int> s;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) s.insert(a[j]-a[i]);
        cout << s.size() << "\n";
    }
    return 0;
}