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
        int n,l,r;
        cin >> n >> l >> r;
        vector<int> a(n+1,0);
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            a[i]=((l+i-1)/i)*i;
            ok&=(a[i]<=r);
        }
        if(ok)
        {
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
        }
        else cout << "NO\n";
    }
    return 0;
}