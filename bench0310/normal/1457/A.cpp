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
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        auto d=[&](int a,int b)->int{return (abs(a-x)+abs(b-y));};
        cout << max({d(1,1),d(n,1),d(1,m),d(n,m)}) << "\n";
    }
    return 0;
}