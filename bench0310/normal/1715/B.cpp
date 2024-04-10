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
        ll n,k,b,s;
        cin >> n >> k >> b >> s;
        if(max(ll(0),s-(n-1)*(k-1))/k<=b&&b<=s/k)
        {
            vector<ll> a(n+1,0);
            int p=n;
            while(s/k>b)
            {
                a[p--]=k-1;
                s-=(k-1);
            }
            a[1]=s;
            for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
        }
        else cout << "-1\n";
    }
    return 0;
}