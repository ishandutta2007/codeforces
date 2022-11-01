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
        string a,b;
        cin >> a >> b;
        bool ok=1;
        for(int i=0;i<n;i++) ok&=(a[i]!='1'||b[i]!='1');
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}