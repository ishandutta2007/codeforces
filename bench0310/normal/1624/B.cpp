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
        auto go=[&](int x,int y)->bool{return (y>0&&(y%x)==0);};
        bool ok=go(a,b-(c-b))|go(b,((a+c)&1)?-1:(a+c)/2)|go(c,b+(b-a));
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}