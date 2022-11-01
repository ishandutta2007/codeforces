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
        if(((x-y)%2)==0) cout << x/2 << " " << (y+1)/2 << "\n";
        else cout << "-1 -1\n";
    }
    return 0;
}