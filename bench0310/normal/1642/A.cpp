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
        vector<array<int,2>> v(3);
        for(auto &[x,y]:v) cin >> x >> y;
        ranges::sort(v,[&](const auto &a,const auto &b){return (a[1]<b[1]);});
        if(v[1][1]==v[2][1]) cout << abs(v[1][0]-v[2][0]) << "\n";
        else cout << "0\n";
    }
    return 0;
}