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
        int l=1;
        while(l+1<=n&&a[l+1]==1) l++;
        int r=n;
        while(r-1>=1&&r-1>=l&&a[r-1]==1) r--;
        cout << r-l << "\n";
    }
    return 0;
}