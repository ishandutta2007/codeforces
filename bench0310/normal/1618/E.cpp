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
        vector<int> b(n,0);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            sum+=b[i];
        }
        int m=(n*(n+1)/2);
        vector<int> a(n,0);
        bool ok=[&]()->bool
        {
            if((sum%m)!=0) return 0;
            ll s=(sum/m);
            for(int i=0;i<n;i++)
            {
                ll x=(b[i]-b[(i+n-1)%n]-s);
                if((x%n)!=0||x>=0) return 0;
                a[i]=-(x/n);
            }
            return 1;
        }();
        if(ok)
        {
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
        }
        else cout << "NO\n";
    }
    return 0;
}