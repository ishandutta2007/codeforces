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
        int n,m,r,c,d;
        cin >> n >> m >> r >> c >> d;
        auto ok=[&](int a,int b)->int{return (abs(r-a)+abs(c-b)>d);};
        bool one=1;
        for(int i=1;i<=n;i++) one&=ok(i,1);
        for(int j=1;j<=m;j++) one&=ok(n,j);
        bool two=1;
        for(int j=1;j<=m;j++) two&=ok(1,j);
        for(int i=1;i<=n;i++) two&=ok(i,m);
        if(one||two) cout << n+m-2 << "\n";
        else cout << "-1\n";
    }
    return 0;
}