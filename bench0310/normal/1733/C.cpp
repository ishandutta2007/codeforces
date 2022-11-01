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
        cout << n-1 << "\n";
        if(n>=2) cout << 1 << " " << n << "\n";
        for(int i=2;i<=n-1;i++)
        {
            if((a[1]+a[i])&1) cout << 1 << " " << i << "\n";
            else cout << i << " " << n << "\n";
        }
    }
    return 0;
}