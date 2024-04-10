#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    const int S=5;
    const array<ll,S> mod={1000000007,rng(1000000009,2000000000),rng(1000000009,2000000000),rng(1000000009,2000000000),rng(1000000009,2000000000)};
    auto add=[&](ll a,ll b,int j)->ll{return a+b-(a+b>=mod[j]?mod[j]:0);};
    const int N=500000;
    vector<array<ll,S>> pw(N);
    pw[0].fill(1);
    for(int i=1;i<N;i++) for(int j=0;j<S;j++) pw[i][j]=add(pw[i-1][j],pw[i-1][j],j);
    using obj=pair<array<ll,S>,array<int,2>>;
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        map<array<ll,S>,int> ini;
        bool zero=1;
        auto process=[&](vector<int> a)->vector<obj>
        {
            vector<array<int,2>> b(n);
            for(int i=0;i<n;i++) b[i]={a[i],i};
            ranges::sort(b);
            array<ll,S> now;
            now.fill(0);
            vector<obj> h;
            int l=0;
            while(l<n)
            {
                int r=l;
                while(r+1<n&&b[r+1][0]==b[l][0]) r++;
                if(r==n-1) break;
                for(int i=l;i<=r;i++) for(int j=0;j<S;j++) now[j]=add(now[j],pw[b[i][1]][j],j);
                array<int,2> lim={b[l][0],b[r+1][0]};
                h.push_back({now,lim});
                if(zero) ini[now]=b[l][0];
                l=r+1;
            }
            return h;
        };
        vector a(n,vector(m,int(0)));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
        auto col=[&](int c,int d)->vector<obj>
        {
            vector<int> tmp;
            for(int i=0;i<n;i++) tmp.push_back(d*a[i][c]);
            return process(tmp);
        };
        col(0,1);
        zero=0;
        vector<map<array<ll,S>,array<int,2>>> ok(m);
        for(auto [one,two]:col(0,1)) ok[0][one]=two;
        for(int i=1;i<m-1;i++)
        {
            for(auto [one,two]:col(i,1))
            {
                if(!ok[i-1].contains(one)) continue;
                auto [x1,y1]=ok[i-1][one];
                auto [x2,y2]=two;
                int x=max(x1,x2);
                int y=min(y1,y2);
                if(x<y) ok[i][one]={x,y};
            }
        }
        map<array<ll,S>,array<int,2>> now;
        for(auto [one,two]:col(m-1,-1)) now[one]=two;
        array<ll,S> req={-1,-1,-1};
        int c=-1;
        for(int i=m-1;i>0;i--)
        {
            map<array<ll,S>,array<int,2>> nxt;
            for(auto [one,two]:col(i,-1))
            {
                if(!now.contains(one)) continue;
                auto [x1,y1]=now[one];
                auto [x2,y2]=two;
                int x=max(x1,x2);
                int y=min(y1,y2);
                if(x<y)
                {
                    if(ok[i-1].contains(one))
                    {
                        req=one;
                        c=i;
                    }
                    nxt[one]={x,y};
                }
            }
            now=nxt;
        }
        if(c!=-1)
        {
            int lim=ini[req];
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << "RB"[a[i][0]<=lim];
            cout << " " << c << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}