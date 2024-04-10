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
        vector<int> c(2*n+1,n);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            c[a]=i-1;
        }
        for(int i=1;i<=2*n;i++) c[i]=min(c[i],c[i-1]);
        int res=2*n;
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            res=min(res,i-1+c[b-1]);
        }
        cout << res << "\n";
    }
    return 0;
}