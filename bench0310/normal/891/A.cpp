#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt=n;
    int g=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt-=(a[i]==1);
        g=gcd(g,a[i]);
    }
    if(g==1)
    {
        int x=n;
        for(int i=0;i<n;i++)
        {
            int now=a[i];
            for(int j=i;j<n;j++)
            {
                now=gcd(now,a[j]);
                if(now==1) x=min(x,j-i);
            }
        }
        cout << x+cnt-(cnt==n) << "\n";
    }
    else cout << "-1\n";
    return 0;
}