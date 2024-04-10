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
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=(a[i]==i);
        int res=0;
        if(ok) res=0;
        else if(a[1]==1||a[n]==n) res=1;
        else if(a[1]!=n||a[n]!=1) res=2;
        else res=3;
        cout << res << "\n";
    }
    return 0;
}