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
        int a,b,c;
        cin >> a >> b >> c;
        int n=2*abs(a-b);
        int res=-1;
        if(max({a,b,c})<=n)
        {
            if(c+n/2<=n) res=c+n/2;
            else res=c-n/2;
        }
        cout << res << "\n";
    }
    return 0;
}