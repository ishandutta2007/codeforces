#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<array<int,2>> p(3);
    vector<int> a,b;
    for(auto &[x,y]:p)
    {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    ranges::sort(a);
    ranges::sort(b);
    int tx=a[1];
    int ty=b[1];
    vector<array<int,4>> res;
    for(auto [x,y]:p)
    {
        if(y!=ty) res.push_back({x,y,x,ty});
        if(x!=tx) res.push_back({x,ty,tx,ty});
    }
    cout << res.size() << "\n";
    for(auto t:res) for(int i=0;i<4;i++) cout << t[i] << " \n"[i==3];
    return 0;
}