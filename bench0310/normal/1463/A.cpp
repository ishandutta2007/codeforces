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
        int x=a+b+c;
        bool ok=1;
        if((x%9)!=0) ok=0;
        int y=x/9;
        if(min({a,b,c})<y) ok=0;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}