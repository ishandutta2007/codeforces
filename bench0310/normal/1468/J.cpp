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
        int n,m,k;
        cin >> n >> m >> k;
        vector<array<int,3>> small,big;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(c<k) small.push_back({a,b,c});
            else big.push_back({a,b,c});
        }
        sort(small.begin(),small.end(),[](const array<int,3> &a,const array<int,3> &b){return (a[2]<b[2]);});
        sort(big.begin(),big.end(),[](const array<int,3> &a,const array<int,3> &b){return (a[2]<b[2]);});
        vector<int> p(n+1,0);
        vector<int> sz(n+1,1);
        for(int i=1;i<=n;i++) p[i]=i;
        ll res=(1ll<<60);
        function<int(int)> find_set=[&](int a)
        {
            if(a==p[a]) return a;
            else return p[a]=find_set(p[a]);
        };
        auto merge_sets=[&](int a,int b)->bool
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b) return 0;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
            return 1;
        };
        int cnt=0;
        for(auto [a,b,c]:small)
        {
            cnt+=merge_sets(a,b);
        }
        if(cnt==n-1)
        {
            res=min(res,(ll)k-small.back()[2]);
            if(!big.empty()) res=min(res,(ll)big.front()[2]-k);
        }
        else
        {
            ll now=0;
            for(auto [a,b,c]:big)
            {
                if(merge_sets(a,b)==1) now+=(c-k);
            }
            res=min(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}