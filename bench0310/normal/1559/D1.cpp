#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct dsu
{
    int n;
    vector<int> p,sz;
    dsu(int m)
    {
        n=m;
        p.assign(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        sz.assign(n+1,1);
    }
    int find_set(int a)
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    }
    bool con(int a,int b)
    {
        return (find_set(a)==find_set(b));
    }
    void merge_sets(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    dsu one(n);
    dsu two(n);
    for(int i=1;i<=m1;i++)
    {
        int a,b;
        cin >> a >> b;
        one.merge_sets(a,b);
    }
    for(int i=1;i<=m2;i++)
    {
        int a,b;
        cin >> a >> b;
        two.merge_sets(a,b);
    }
    vector<array<int,2>> res;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(!one.con(i,j)&&!two.con(i,j))
            {
                res.push_back({i,j});
                one.merge_sets(i,j);
                two.merge_sets(i,j);
            }
        }
    }
    assert((int)res.size()==n-1-max(m1,m2));
    cout << res.size() << "\n";
    for(auto [a,b]:res) cout << a << " " << b << "\n";
    return 0;
}