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
        int r,g,b,w;
        cin >> r >> g >> b >> w;
        if(((r&1)+(g&1)+(b&1)+(w&1)<=1)||(min({r,g,b})>=1&&((r-1)&1)+((g-1)&1)+((b-1)&1)+((w+1)&1)<=1)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}