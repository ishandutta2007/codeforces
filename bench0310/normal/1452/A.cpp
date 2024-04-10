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
        int x,y;
        cin >> x >> y;
        x=abs(x);
        y=abs(y);
        int m=min(x,y);
        int r=x+y-2*m;
        cout << 2*m+max(0,2*r-1) << "\n";
    }
    return 0;
}