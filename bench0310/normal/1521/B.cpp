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
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        array<int,2> m={0,0};
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(i==1) m={a[i],i};
            m=min(m,{a[i],i});
        }
        vector<array<int,4>> v;
        if(m[1]!=1) v.push_back({1,m[1],m[0],m[0]});
        for(int i=2;i<=n;i++)
        {
            v.push_back({1,i,m[0],m[0]+((i&1)==0)});
        }
        cout << v.size() << "\n";
        for(auto [i,j,x,y]:v) cout << i << " " << j << " " << x << " " << y << "\n";
    }
    return 0;
}