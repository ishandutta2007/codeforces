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
        multiset<int> l,r;
        auto add=[&](int a,int b)
        {
            l.insert(a);
            r.insert(b);
        };
        auto rm=[&](int a,int b)
        {
            l.erase(l.find(a));
            r.erase(r.find(b));
        };
        auto nxt=[&](multiset<int> &s,int x)->int
        {
            auto it=s.lower_bound(x);
            if(it!=s.end()) return (*it);
            else return 2000000000;
        };
        auto prv=[&](multiset<int> &s,int x)->int
        {
            auto it=s.upper_bound(x);
            if(it!=s.begin()) return (*prev(it));
            else return -1000000000;
        };
        auto go=[&](int a,int b)->int
        {
            if(nxt(r,a)<=b||prv(l,b)>=a) return 0;
            return min(a-prv(r,a),nxt(l,b)-b); 
        };
        vector<array<int,3>> v[n+1];
        vector<array<int,4>> e(n);
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[c].push_back({a,b,i});
            e[i-1]={a,b,c,i};
            add(a,b);
        }
        vector<int> res(n+1,(1<<30));
        for(int i=1;i<=n;i++)
        {
            for(auto [a,b,j]:v[i]) rm(a,b);
            for(auto [a,b,j]:v[i]) res[j]=min(res[j],go(a,b));
            for(auto [a,b,j]:v[i]) add(a,b);
        }
        multiset<array<int,2>> s;
        vector<int> opt(n+1,0);
        for(int i=1;i<=n;i++) s.insert({opt[i],i});
        ranges::sort(e);
        for(auto [a,b,c,j]:e)
        {
            s.erase(s.find({opt[c],c}));
            opt[c]=max(opt[c],b);
            s.insert({opt[c],c});
            auto it=s.rbegin();
            if((*it)[1]==c) it++;
            if((*it)[0]>=b) res[j]=0;
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}