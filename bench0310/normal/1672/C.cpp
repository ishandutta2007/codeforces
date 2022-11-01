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
        int l=n+1,r=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l==n+1||l==r) cout << "0\n";
        else cout << max(1,r-l-1) << "\n";
    }
    return 0;
}