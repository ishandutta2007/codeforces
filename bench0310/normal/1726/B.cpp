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
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1,0);
        bool ok=[&]()->bool
        {
            if(n>m) return 0;
            if((n%2)==0)
            {
                if(m&1) return 0;
                for(int i=1;i<=n-2;i++) a[i]=1;
                a[n-1]=a[n]=(m-(n-2))/2;
            }
            else
            {
                for(int i=1;i<=n-1;i++) a[i]=1;
                a[n]=(m-(n-1));
            }
            return 1;
        }();
        if(ok)
        {
            cout << "Yes\n";
            for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
        }
        else cout << "No\n";
    }
    return 0;
}