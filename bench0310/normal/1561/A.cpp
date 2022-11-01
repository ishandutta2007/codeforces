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
        int res=0;
        while(1)
        {
            bool ok=1;
            for(int i=1;i<n;i++) ok&=(a[i]<a[i+1]);
            if(ok) break;
            for(int i=1+(res&1);i+1<=n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}