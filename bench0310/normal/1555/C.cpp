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
        int m;
        cin >> m;
        vector<int> a(m+2,0);
        for(int i=1;i<=m;i++) cin >> a[i];
        vector<int> b(m+2,0);
        for(int i=1;i<=m;i++) cin >> b[i];
        vector<int> sa(m+2,0);
        for(int i=m;i>=0;i--) sa[i]=sa[i+1]+a[i];
        vector<int> sb(m+2,0);
        for(int i=1;i<=m+1;i++) sb[i]=sb[i-1]+b[i];
        int res=sa[2];
        for(int i=1;i<=m;i++) res=min(res,max(sa[i+1],sb[i-1]));
        cout << res << "\n";
    }
    return 0;
}