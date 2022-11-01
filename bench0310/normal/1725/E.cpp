#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n;
    cin >> n;
    vector<int> e[N+1];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        while(a>1)
        {
            int p=sieve[a];
            while(sieve[a]==p) a/=p;
            e[p].push_back(i);
        }
    }
    vector<vector<int>> v(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<array<int,18>> up(n+1);
    for(int i=0;i<=n;i++) up[i].fill(0);
    vector<int> depth(n+1,0);
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    int tcnt=0;
    auto dfs=[&](auto &&_dfs,int a)->void
    {
        depth[a]=depth[up[a][0]]+1;
        tin[a]=(++tcnt);
        for(int i=1;i<18;i++) up[a][i]=up[up[a][i-1]][i-1];
        for(int to:v[a])
        {
            if(to==up[a][0]) continue;
            up[to][0]=a;
            _dfs(_dfs,to);
        }
        tout[a]=tcnt;
    };
    dfs(dfs,1);
    auto sub=[&](int a,int b)->bool{return (tin[a]<=tin[b]&&tin[b]<=tout[a]);};
    auto lca=[&](int a,int b)->int
    {
        if(depth[a]>depth[b]) swap(a,b);
        for(int i=17;i>=0;i--) if(depth[up[b][i]]>=depth[a]) b=up[b][i];
        if(a==b) return a;
        for(int i=17;i>=0;i--) if(up[a][i]!=up[b][i]) tie(a,b)={up[a][i],up[b][i]};
        return up[a][0];
    };
    vector<int> on(n+1,0);
    mi res=0;
    vector<vector<array<int,2>>> g(n+1);
    vector<mi> oncnt(n+1,0);
    vector<mi> down(n+1,0);
    for(int prime=1;prime<=N;prime++)
    {
        vector<int> nodes=e[prime];
        if(nodes.empty()) continue;
        for(int x:e[prime]) on[x]=1;
        int onall=e[prime].size();
        ranges::sort(nodes,[&](int a,int b){return (tin[a]<tin[b]);});
        for(int i=(int)nodes.size()-1;i>=1;i--) nodes.push_back(lca(nodes[i-1],nodes[i]));
        ranges::sort(nodes,[&](int a,int b){return (tin[a]<tin[b]);});
        nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
        vector<int> s;
        for(int x:nodes)
        {
            if(s.empty()) s.push_back(x);
            else
            {
                while(!sub(s.back(),x)) s.pop_back();
                g[s.back()].push_back({x,depth[x]-depth[s.back()]});
                s.push_back(x);
            }
        }
        int root=nodes[0];
        auto prep=[&](auto &&_prep,int a)->void
        {
            oncnt[a]=(on[a]==1);
            for(auto [to,d]:g[a])
            {
                _prep(_prep,to);
                oncnt[a]+=oncnt[to];
                down[a]+=down[to];
                down[a]+=(ll(d)*oncnt[to]);
            }
        };
        prep(prep,root);
        auto go=[&](auto &&_go,int a,mi eup)->void
        {
            mi tmp=0;
            for(auto [to,d]:g[a]) tmp+=(down[to]+ll(d)*oncnt[to]);
            int onup=onall-oncnt[a];
            for(auto [to,d]:g[a]) _go(_go,to,eup+tmp-(down[to]+ll(d)*oncnt[to])+ll(d)*(onall-oncnt[to]));
            vector<mi> te={0};
            for(auto [to,d]:g[a]) te.push_back(mi(down[to]+ll(d)*oncnt[to]));
            te.push_back(eup);
            vector<mi> ton={0};
            for(auto [to,d]:g[a]) ton.push_back(oncnt[to]);
            ton.push_back(onup);
            int ch=(int)g[a].size()+1;
            vector<mi> suml(ch+2,0);
            vector<mi> pairsl(ch+2,0);
            for(int i=1;i<=ch;i++)
            {
                suml[i]=suml[i-1]+ton[i];
                pairsl[i]=pairsl[i-1]+ton[i]*suml[i-1];
            }
            vector<mi> sumr(ch+2,0);
            vector<mi> pairsr(ch+2,0);
            for(int i=ch;i>=1;i--)
            {
                sumr[i]=sumr[i+1]+ton[i];
                pairsr[i]=pairsr[i+1]+ton[i]*sumr[i+1];
            }
            for(int i=1;i<=ch;i++)
            {
                //path
                if(on[a]==1) res+=(te[i]*(onall-1-ton[i]));
                //split
                res+=(te[i]*(pairsl[i-1]+pairsr[i+1]+suml[i-1]*sumr[i+1]));
            }
        };
        go(go,root,0);
        for(int x:e[prime]) on[x]=0;
        for(int x:nodes)
        {
            g[x].clear();
            oncnt[x]=down[x]=0;
        }
    }
    cout << res << "\n";
    return 0;
}