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
        int m=(1<<30);
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=min(m,a[i]);
        }
        int g=0;
        for(int i=1;i<=n;i++) g=gcd(g,a[i]-m);
        if(g==0) g=-1;
        cout << g << "\n";
    }
    return 0;
}