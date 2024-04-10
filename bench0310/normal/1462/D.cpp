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
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        int res=1;
        for(int i=2;i<=n;i++)
        {
            if((sum%i)!=0) continue;
            int x=(sum/i);
            bool ok=1;
            int now=0;
            for(int j=1;j<=n;j++)
            {
                now+=a[j];
                if(now==x) now=0;
                else if(now>x) ok=0;
            }
            if(ok) res=i;
        }
        cout << n-res << "\n";
    }
    return 0;
}