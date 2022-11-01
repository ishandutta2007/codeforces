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
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
        int l=1,r=n+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            int c=0;
            for(int i=1;i<=n;i++) c+=(c<=b[i]&&m-1-c<=a[i]);
            if(c>=m) l=m;
            else r=m;
        }
        cout << l << "\n";
    }
    return 0;
}