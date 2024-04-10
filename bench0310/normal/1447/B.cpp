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
        int mn=100;
        int sum=0;
        int neg=0;
        for(int i=0;i<n*m;i++)
        {
            int a;
            cin >> a;
            mn=min(mn,abs(a));
            sum+=abs(a);
            if(a<0) neg^=1;
        }
        if(mn==0||neg==0) cout << sum << "\n";
        else cout << sum-2*mn << "\n";
    }
    return 0;
}