#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<int>> res;
    auto mv=[&](vector<int> v)
    {
        vector<int> u;
        for(int sz:v) if(sz>0) u.push_back(sz);
        v=u;
        if(v.size()==1) return;
        res.push_back(v);
        vector<vector<int>> tmp;
        int l=1;
        for(int sz:v)
        {
            int r=l+sz-1;
            vector<int> z;
            for(int i=l;i<=r;i++) z.push_back(a[i]);
            tmp.push_back(z);
            l+=sz;
        }
        reverse(tmp.begin(),tmp.end());
        a={0};
        for(auto z:tmp) for(int x:z) a.push_back(x);
    };
    while(1)
    {
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=(a[i]==i);
        if(ok) break;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[a[i]]=i;
        int x=0;
        for(int i=1;i<n;i++) if(p[i]>p[i+1]) x=i;
        vector<int> v={p[x+1]-1};
        int l=p[x+1];
        while(a[l]+1==a[l+1]) l++;
        v.push_back(l-p[x+1]+1);
        v.push_back(p[x]-l);
        v.push_back(n-p[x]);
        mv(v);
    }
    cout << res.size() << "\n";
    for(vector<int> v:res)
    {
        cout << v.size();
        for(int sz:v) cout << " " << sz;
        cout << "\n";
    }
    return 0;
}