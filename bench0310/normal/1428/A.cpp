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
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2&&y1==y2) cout << "0\n";
        else if(x1==x2||y1==y2) cout << abs(x1-x2)+abs(y1-y2) << "\n";
        else cout << abs(x1-x2)+abs(y1-y2)+2 << "\n";
    }
    return 0;
}