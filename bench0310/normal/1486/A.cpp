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
        bool ok=1;
        ll s=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            s+=a;
            ok&=(s>=i);
            s-=i;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}