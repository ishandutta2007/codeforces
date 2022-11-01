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
        int res=n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int da=a[j]-a[i];
                int db=j-i;
                int c=0;
                for(int k=1;k<=n;k++)
                {
                    if(k==i||k==j) continue;
                    if(((k-i)*(da))%db==0) c+=(a[k]!=a[i]+((k-i)*da/db));
                    else c++;
                }
                res=min(res,c);
            }
        }
        cout << res << "\n";
    }
    return 0;
}