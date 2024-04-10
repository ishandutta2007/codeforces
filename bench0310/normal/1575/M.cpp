#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct line
{
    ll k,n;
    line(ll _k,ll _n){k=_k;n=_n;}
    ll e(ll x){return (k*x+n);}
    friend bool bad(line &a,line &b,line &c){return ((b.n-a.n)*(b.k-c.k)>(c.n-b.n)*(a.k-b.k));}
};

struct cht
{
    vector<line> v;
    void add(ll k,ll n)
    {
        line l(k,n);
        while(v.size()>=2&&bad(v[v.size()-2],v.back(),l)) v.pop_back();
        v.push_back(l);
    }
    ll e(ll x)
    {
        while(v.size()>=2&&v[v.size()-2].e(x)<v.back().e(x)) v.pop_back();
        return v.back().e(x);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> a(n+1);
    for(int i=0;i<=n;i++) cin >> a[i];
    vector y(n+1,vector(m+1,int(-1)));
    auto sq=[&](int x)->int{return (x*x);};
    for(int j=0;j<=m;j++)
    {
        vector<int> v={2*n};
        for(int i=n;i>=0;i--) if(a[i][j]=='1') v.push_back(i);
        if(v.size()==1) continue;
        int u=-n;
        for(int i=0;i<=n;i++)
        {
            if(a[i][j]=='1')
            {
                u=i;
                v.pop_back();
            }
            y[i][j]=min(sq(i-u),sq(i-v.back()));
        }
    }
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        cht opt;
        for(int j=0;j<=m;j++) if(y[i][j]!=-1) opt.add(-2*j,sq(j)+y[i][j]);
        for(int j=m;j>=0;j--) res+=(opt.e(j)+sq(j));
    }
    cout << res << "\n";
    return 0;
}