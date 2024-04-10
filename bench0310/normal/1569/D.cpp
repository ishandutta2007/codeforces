#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> now(1000001,0);
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        set<int> v,h;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            v.insert(x);
        }
        for(int i=1;i<=m;i++)
        {
            int y;
            cin >> y;
            h.insert(y);
        }
        vector<array<int,3>> one; //only vertical
        vector<array<int,3>> two; //only horizontal
        auto is_v=[&](int x)->bool{return (v.find(x)!=v.end());};
        auto is_h=[&](int y)->bool{return (h.find(y)!=h.end());};
        for(int i=1;i<=k;i++)
        {
            int x,y;
            cin >> x >> y;
            if(is_v(x)&&!is_h(y)) one.push_back({y,x,1});
            if(!is_v(x)&&is_h(y)) two.push_back({x,y,1});
        }
        for(int y:h) one.push_back({y,0,0});
        for(int x:v) two.push_back({x,0,0});
        auto p=[&](ll a)->ll{return (a*(a-1)/2);};
        auto go=[&](vector<array<int,3>> &e)->ll
        {
            sort(e.begin(),e.end());
            int sz=e.size();
            int l=0;
            ll res=0;
            while(l<sz)
            {
                if(e[l][2]==0)
                {
                    l++;
                    continue;
                }
                int r=l;
                while(r+1<sz&&e[r+1][2]==1) r++;
                res+=p(r-l+1);
                for(int i=l;i<=r;i++)
                {
                    res+=p(now[e[i][1]]);
                    res-=p(++now[e[i][1]]);
                }
                for(int i=l;i<=r;i++) now[e[i][1]]=0;
                l=r+1;
            }
            return res;
        };
        cout << go(one)+go(two) << "\n";
    }
    return 0;
}