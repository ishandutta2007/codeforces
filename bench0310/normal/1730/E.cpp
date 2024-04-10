#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct fenwick
{
    int n;
    vector<int> t;
    vector<int> c;
    int all=0;
    void ini(int _n){n=_n;t.assign(n+1,0);c.assign(n+1,0);}
    void upd(int p,int d)
    {
        all+=d;
        c[p]+=d;
        for(;p<=n;p=(p|(p+1))) t[p]+=d;
    }
    int qry(int p){return c[p];}
    int sum(int p)
    {
        p--;
        int s=0;
        for(;p>=0;p=(p&(p+1))-1) s+=t[p];
        return all-s;
    }
};

const int N=1000000;
vector<int> d[N+1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) d[j].push_back(i);
    vector<int> one(N+1,0);
    vector<int> two(N+1,0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        ll res=0;
        vector<fenwick> st(2);
        for(int i=0;i<2;i++) st[i].ini(N);
        vector<array<int,3>> e;
        auto go=[&](auto &&self,int l,int r)->void
        {
            if(l==r)
            {
                res++;
                return;
            }
            int m=(l+r)/2;
            int x=N,y=0;
            for(int i=m;i>=l;i--)
            {
                x=min(x,a[i]);
                y=max(y,a[i]);
                e.push_back({y,x,0});
            }
            x=N;y=0;
            for(int i=m+1;i<=r;i++)
            {
                x=min(x,a[i]);
                y=max(y,a[i]);
                e.push_back({y,x,1});
            }
            ranges::sort(e);
            for(auto [mx,mn,c]:e)
            {
                st[c].upd(mn,1);
                for(int b:d[mx])
                {
                    if(b<mn) res+=st[1-c].qry(b);
                    else break;
                }
                if((mx%mn)==0) res+=st[1-c].sum(mn);
            }
            for(auto [mx,mn,c]:e) st[c].upd(mn,-1);
            e.clear();
            self(self,l,m);
            self(self,m+1,r);
        };
        go(go,1,n);
        cout << res << "\n";
    }
    return 0;
}