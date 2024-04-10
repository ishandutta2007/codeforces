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
        int res=n;
        for(int i=1;i<=min(n,100000);i++) res=min(res,i-1+max(0,(n-i+i-1)/i));
        cout << res << "\n";
    }
    return 0;
}