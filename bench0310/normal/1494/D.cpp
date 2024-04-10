#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> val(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> val[i][j];
    int id=n;
    vector<array<int,2>> edges;
    vector<int> res(n+1,0);
    for(int i=1;i<=n;i++) res[i]=val[i][i];
    function<void(int,vector<int>)> solve=[&](int root,vector<int> v)
    {
        if(v.empty()) return;
        int sz=v.size();
        int a=v[0];
        vector<array<int,2>> opt;
        for(int i=1;i<sz;i++) opt.push_back({val[a][v[i]],v[i]});
        sort(opt.begin(),opt.end());
        int l=0;
        vector<int> chain;
        chain.push_back(a);
        while(l<sz-1)
        {
            int r=l;
            while(r+1<sz-1&&opt[r+1][0]==opt[l][0]) r++;
            vector<int> nv;
            for(int i=l;i<=r;i++) nv.push_back(opt[i][1]);
            int nroot=0;
            if(opt[l][0]!=res[root])
            {
                id++;
                res.push_back(opt[l][0]);
                chain.push_back(id);
                nroot=id;
            }
            else nroot=root;
            solve(nroot,nv);
            l=r+1;
        }
        chain.push_back(root);
        for(int i=0;i<(int)chain.size()-1;i++) edges.push_back({chain[i],chain[i+1]});
    };
    vector<int> v(n);
    for(int i=0;i<n;i++) v[i]=i+1;
    solve(0,v);
    int root=0;
    for(auto [a,b]:edges) if(b==0) root=a;
    cout << id << "\n";
    for(int i=1;i<=id;i++) cout << res[i] << " \n"[i==id];
    cout << root << "\n";
    for(auto [a,b]:edges) if(b!=0) cout << a << " " << b << "\n";
    return 0;
}