#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll now=0;
ll c(ll a){return (a*(a+1)/2);}
ll c(set<array<int,2>>::iterator it){return c((*it)[1]-(*it)[0]+1);}

struct obj
{
    set<int> active;
    set<array<int,2>> s;
    void add(int a)
    {
        active.insert(a);
        auto it=s.lower_bound({a+1,0});
        int l=a,r=a;
        if(active.count(a+1))
        {
            r=(*it)[1];
            now-=c(it);
            it=s.erase(it);
        }
        if(active.count(a-1))
        {
            it--;
            l=(*it)[0];
            now-=c(it);
            s.erase(it);
        }
        now+=c(s.insert({l,r}).first);
    }
    void rm(int a)
    {
        active.erase(a);
        auto it=s.lower_bound({a+1,0});
        it--;
        now-=c(it);
        auto [l,r]=(*it);
        s.erase(it);
        if(l<=a-1) now+=c(s.insert({l,a-1}).first);
        if(a+1<=r) now+=c(s.insert({a+1,r}).first);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<obj> v(n+m);
    int active=n*m;
    vector a(n+1,vector(m+1,int(1)));
    auto one=[&](int r,int c)->array<int,2> //o,b
    {
        int o=r-c;
        return {o+m,2*c-1};
    };
    auto two=[&](int r,int c)->array<int,2> //o,b
    {
        int o=r-c-1;
        return {o+m,2*c};
    };
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            auto [o1,b1]=one(i,j);
            v[o1].add(b1);
            auto [o2,b2]=two(i,j);
            v[o2].add(b2);
        }
    }
    while(q--)
    {
        int r,c;
        cin >> r >> c;
        auto [o1,b1]=one(r,c);
        auto [o2,b2]=two(r,c);
        if(a[r][c]==0)
        {
            active++;
            v[o1].add(b1);
            v[o2].add(b2);
        }
        else
        {
            active--;
            v[o1].rm(b1);
            v[o2].rm(b2);
        }
        a[r][c]^=1;
        cout << now-active << "\n";
    }
    return 0;
}