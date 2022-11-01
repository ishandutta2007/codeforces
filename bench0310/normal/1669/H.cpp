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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int res=0;
        for(int j=30;j>=0;j--)
        {
            int c=0;
            for(int i=1;i<=n;i++) c+=(((a[i]>>j)&1)==0);
            if(k>=c)
            {
                k-=c;
                res+=(1<<j);
            }
        }
        cout << res << "\n";
    }
    return 0;
}