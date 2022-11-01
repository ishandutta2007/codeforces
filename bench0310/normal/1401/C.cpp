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
        int m=(1<<30);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=min(m,a[i]);
        }
        vector<int> v;
        for(int i=1;i<=n;i++) if((a[i]%m)==0) v.push_back(a[i]);
        sort(v.begin(),v.end());
        int idx=0;
        for(int i=1;i<=n;i++) if((a[i]%m)==0) a[i]=v[idx++];
        bool ok=1;
        for(int i=1;i<n;i++) ok&=(a[i]<=a[i+1]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}