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
        vector<array<int,4>> v(n);
        set<array<int,2>> s[2];
        for(int i=0;i<n;i++)
        {
            auto &[r,l,c,j]=v[i];
            cin >> c >> l >> r;
            j=i;
            s[c].insert({r,i});
        }
        ranges::sort(v);
        vector<int> p(n,0);
        for(int i=0;i<n;i++) p[i]=i;
        vector<int> sz(n,1);
        function<int(int)> find_set=[&](int a)->int
        {
            if(a==p[a]) return a;
            else return p[a]=find_set(p[a]);
        };
        int g=n;
        auto merge_sets=[&](int a,int b)
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b) return;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
            g--;
        };
        for(auto [r,l,c,j]:v)
        {
            array<int,2> tmp={-1,-1};
            while(1)
            {
                auto it=s[c^1].lower_bound({l,0});
                if(it==s[c^1].end()||(*it)[0]>r) break;
                merge_sets(j,(*it)[1]);
                tmp=(*it);
                s[c^1].erase(it);
            }
            if(tmp[0]!=-1) s[c^1].insert(tmp);
        }
        cout << g << "\n";
    }
    return 0;
}