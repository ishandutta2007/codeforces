#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d,n;
    cin >> d >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        a[i]=stoi(s,0,2);
    }
    sort(a.begin(),a.end(),[&](int x,int y){return (__builtin_popcount(x)>__builtin_popcount(y));});
    vector<int> v[n];
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if((a[i]&a[j])==a[i]) v[i].push_back(j);
        }
    }
    vector<int> mt(n,-1);
    vector<bool> vis(n,0);
    function<bool(int)> match=[&](int e)->bool
    {
        if(vis[e]) return 0;
        vis[e]=1;
        for(int to:v[e])
        {
            if(mt[to]==-1||match(mt[to]))
            {
                mt[to]=e;
                return 1;
            }
        }
        return 0;
    };
    for(int i=0;i<n;i++)
    {
        vis.assign(n,0);
        match(i);
    }
    vector<int> nxt(n,-1);
    for(int i=0;i<n;i++) if(mt[i]!=-1) nxt[mt[i]]=i;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(nxt[i]!=-1) continue;
        vector<int> t={i};
        while(mt[t.back()]!=-1) t.push_back(mt[t.back()]);
        reverse(t.begin(),t.end());
        int m=0;
        for(int j:t)
        {
            int x=(m^a[j]);
            m=a[j];
            for(int k=0;k<d;k++) if(x&(1<<k)) res.push_back(k);
        }
        res.push_back(-1);
    }
    res.pop_back();
    cout << res.size() << "\n";
    for(int x:res)
    {
        if(x!=-1) cout << x << " ";
        else cout << "R ";
    }
    cout << "\n";
    return 0;
}