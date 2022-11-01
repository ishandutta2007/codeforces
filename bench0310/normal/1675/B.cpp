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
        bool ok=1;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i+1]==0) ok=0;
            else
            {
                while(a[i]>=a[i+1])
                {
                    res++;
                    a[i]/=2;
                }
            }
        }
        if(ok==0) res=-1;
        cout << res << "\n";
    }
    return 0;
}