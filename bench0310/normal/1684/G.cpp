#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> one,two;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(3*ll(a)>m) one.push_back(a);
        else two.push_back(a);
    }
    int l=one.size();
    int r=two.size();
    vector<int> v[l];
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<r;j++)
        {
            if((one[i]%two[j])==0&&ll(2*one[i])+two[j]<=m) v[i].push_back(j);
        }
    }
    vector<int> mt(r,-1);
    vector<bool> vis(l,0);
    bool ok=1;
    function<bool(int)> go=[&](int a)->bool
    {
        if(vis[a]) return 0;
        vis[a]=1;
        for(int to:v[a])
        {
            if(mt[to]==-1||go(mt[to]))
            {
                mt[to]=a;
                return 1;
            }
        }
        return 0;
    };
    for(int i=0;i<l;i++)
    {
        vis.assign(l,0);
        ok&=go(i);
    }
    if(ok)
    {
        cout << l+(r-l) << "\n";
        vector<int> to(l,-1);
        for(int i=0;i<r;i++) if(mt[i]!=-1) to[mt[i]]=i;
        for(int i=0;i<l;i++) cout << 2*one[i]+two[to[i]] << " " << one[i]+two[to[i]] << "\n";
        for(int i=0;i<r;i++) if(mt[i]==-1) cout << 3*two[i] << " " << 2*two[i] << "\n";
    }
    else cout << "-1\n";
    return 0;
}