#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a[n+1];
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        a[i].assign(c[i]+1,0);
        for(int j=1;j<=c[i];j++) cin >> a[i][j];
    }
    int m;
    cin >> m;
    vector<pair<int,vector<int>>> v;
    v.push_back({0,vector<int>(n+1,0)});
    for(int i=1;i<=n;i++)
    {
        vector<pair<int,vector<int>>> u;
        set<array<int,3>> s;
        auto f=[&](int x,int y)->int{return (v[x].first+a[i][y]);};
        int sz=v.size();
        s.insert({f(sz-1,c[i]),sz-1,c[i]});
        while((int)u.size()<m+1&&!s.empty())
        {
            auto [val,x,y]=*s.rbegin();
            s.erase({val,x,y});
            vector<int> t=v[x].second;
            t[i]=y;
            u.push_back({val,t});
            if(x-1>=0&&s.find({f(x-1,y),x-1,y})==s.end()) s.insert({f(x-1,y),x-1,y});
            if(y-1>=1&&s.find({f(x,y-1),x,y-1})==s.end()) s.insert({f(x,y-1),x,y-1});
        }
        reverse(u.begin(),u.end());
        v=u;
    }
    set<vector<int>> bad;
    for(int i=1;i<=m;i++)
    {
        vector<int> t(n+1,0);
        for(int j=1;j<=n;j++) cin >> t[j];
        bad.insert(t);
    }
    assert((int)v.size()==m+1);
    for(int i=m;i>=0;i--)
    {
        if(bad.find(v[i].second)==bad.end())
        {
            for(int j=1;j<=n;j++) cout << v[i].second[j] << " \n"[j==n];
            break;
        }
    }
    return 0;
}