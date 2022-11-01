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
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        ll res=0;
        for(int i=1;i<=n;i++) res+=max(0,(int)(upper_bound(a.begin(),a.end(),r-a[i])-max(lower_bound(a.begin(),a.end(),l-a[i]),a.begin()+i+1)));
        cout << res << "\n";
    }
    return 0;
}