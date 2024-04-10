#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    
    int s = abs(x) + abs(y);
    
    if(x > 0 && y > 0)
        cout << 0 << ' ' << s << ' ' << s << ' ' << 0;
    else if(x > 0)
        cout << 0 << ' ' << -s << ' ' << s << ' ' << 0;
    else if(y > 0)
        cout << -s << ' ' << 0 << ' ' << 0 << ' ' << s;
    else cout << -s << ' ' << 0 << ' ' << 0 << ' ' << -s;
}