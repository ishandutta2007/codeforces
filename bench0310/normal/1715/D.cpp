#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<array<int,2>> v[30];
    vector bad(n+1,vector(30,bool(0)));
    for(int i=1;i<=q;i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        if(a>b) swap(a,b);
        for(int j=0;j<30;j++)
        {
            if((x>>j)&1) v[j].push_back({a,b});
            else bad[a][j]=bad[b][j]=1;
        }
    }
    vector<int> a(n+1,0);
    vector<int> e[n+1];
    for(int b=0;b<30;b++)
    {
        ranges::sort(v[b]);
        for(auto [i,j]:v[b]) e[i].push_back(j);
        for(int i=1;i<=n;i++)
        {
            bool f=0;
            for(int j:e[i]) f|=bad[j][b];
            if(f) a[i]|=(1<<b);
            for(int j:e[i]) if(((a[i]>>b)&1)==0) a[j]|=(1<<b);
        }
        for(int i=1;i<=n;i++) e[i].clear();
    }
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    return 0;
}