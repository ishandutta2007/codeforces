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
        int c=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            c+=(a[i]<0);
            a[i]=abs(a[i]);
        }
        for(int i=1;i<=c;i++) a[i]=-a[i];
        bool ok=1;
        for(int i=1;i<n;i++) ok&=(a[i]<=a[i+1]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}