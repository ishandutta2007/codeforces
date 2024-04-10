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
        int g=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            g=gcd(g,a);
        }
        int res=0;
        if(n==1) res=(g!=1);
        else if(g==1) res=0;
        else if(gcd(g,n)==1) res=1;
        else if(gcd(g,n-1)==1) res=2;
        else res=3;
        cout << res << "\n";
    }
    return 0;
}