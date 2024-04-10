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
        int n,m;
        cin >> n >> m;
        auto g=[&](int a,int b,int c,int d)->int{return abs(a-c)+abs(b-d);};
        vector<int> v;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) v.push_back(max({g(i,j,1,1),g(i,j,n,1),g(i,j,1,m),g(i,j,n,m)}));
        ranges::sort(v);
        for(int i=0;i<n*m;i++) cout << v[i] << " \n"[i==n*m-1];
    }
    return 0;
}