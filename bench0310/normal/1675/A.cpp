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
        int a,b,c,x,y;
        cin >> a >> b >> c >> x >> y;
        x=max(0,x-a);
        y=max(0,y-b);
        if(c>=x+y) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}