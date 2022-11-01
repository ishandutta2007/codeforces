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
        for(int &y:b) cin >> y;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            ok&=(a[i]<=b[i]);
            if(a[i]<b[i]) ok&=(b[i]<=b[(i+1)%n]+1);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}