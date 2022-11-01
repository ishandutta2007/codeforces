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
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(!(min(a,b)>max(c,d)||max(a,b)<min(c,d))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}