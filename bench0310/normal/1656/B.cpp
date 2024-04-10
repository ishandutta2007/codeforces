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
        int n,k;
        cin >> n >> k;
        map<int,int> c;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            c[a[i]]--;
            ok|=(c[k+a[i]]>0);
            c[a[i]]++;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}