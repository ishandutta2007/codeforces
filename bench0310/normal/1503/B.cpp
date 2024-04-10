#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[3];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v[(i+j)%2+1].push_back({i,j});
    auto col=[&](int b,int t)
    {
        auto [r,c]=v[t].back();
        v[t].pop_back();
        cout << b << " " << r << " " << c << "\n";
        cout.flush();
    };
    for(int i=1;i<=n*n;i++)
    {
        int a;
        cin >> a;
        if(a!=1&&(!v[1].empty())) col(1,1);
        else if(a!=2&&(!v[2].empty())) col(2,2);
        else if(!v[1].empty()) col(3,1);
        else col(3,2);
    }
    return 0;
}