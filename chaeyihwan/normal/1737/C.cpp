#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x, y; cin >> x >> y;
    
    int odd = 0;
    if((x1+y1+x2+y2+x3+y3)%2 == 0) odd = 1;
    if(odd == 0)
    {
        if((x2+y2)%2 == 1)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        if((x3+y3)%2 == 1)
        {
            swap(x1, x3);
            swap(y1, y3);
        }
        
        if(x1 == 1 && y1 == n)
        {
            bool flag = false;
            if(x == 1 || y == n) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        if(x1 == n && y1 == 1)
        {
            bool flag = false;
            if(x == n || y == 1) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        
        if((x+y)%2 == 0) cout << "YES\n";
        else if((x1+x)%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else
    {
        if((x2+y2)%2 == 0)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        if((x3+y3)%2 == 0)
        {
            swap(x1, x3);
            swap(y1, y3);
        }
        
        if(x1 == 1 && y1 == 1)
        {
            if(x == 1 || y == 1) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        if(x1 == n && y1 == n)
        {
            if(x == n || y == n) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        if(x1 == 1 && y1 == n)
        {
            bool flag = false;
            if(x == 1 || y == n) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        if(x1 == n && y1 == 1)
        {
            bool flag = false;
            if(x == n || y == 1) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
        
        if((x+y)%2 == 1) cout << "YES\n";
        else if((x1+x)%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}