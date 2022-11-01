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
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> sieve(n+1,0);
        for(int i=1;i<=n;i++) sieve[i]=i;
        for(int i=2;i*i<=n;i++)
        {
            if(sieve[i]!=i) continue;
            for(int j=i*i;j<=n;j+=i) if(sieve[j]==j) sieve[j]=i;
        }
        auto primes=[&](int a)->vector<int>
        {
            vector<int> p;
            while(a>1)
            {
                p.push_back(sieve[a]);
                a/=sieve[a];
            }
            return p;
        };
        vector<array<int,3>> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b,x,y;
            cin >> a >> b >> x >> y;
            v[a].push_back({b,y,x}); //a->b <=> b=a*x/y
            v[b].push_back({a,x,y});
        }
        vector<int> mx(n+1,0);
        vector<int> num(n+1,0);
        vector<int> den(n+1,0);
        auto add=[&](int p)
        {
            if(den[p]==0) num[p]++;
            else den[p]--;
        };
        auto rm=[&](int p)
        {
            if(num[p]==0) den[p]++;
            else num[p]--;
        };
        function<void(int,int)> dfs=[&](int a,int u)
        {
            for(auto [to,x,y]:v[a])
            {
                if(to==u) continue;
                vector<int> one=primes(x);
                vector<int> two=primes(y);
                for(int p:one) add(p);
                for(int p:two) rm(p);
                for(int p:one) mx[p]=max(mx[p],den[p]);
                for(int p:two) mx[p]=max(mx[p],den[p]);
                dfs(to,a);
                for(int p:one) rm(p);
                for(int p:two) add(p);
            }
        };
        dfs(1,0);
        mi one=1;
        mi res=0;
        for(int i=1;i<=n;i++) one*=pow(mi(i),mx[i]);
        function<void(int,int,mi)> go=[&](int a,int p,mi val)        
        {
            res+=val;
            for(auto [to,x,y]:v[a])
            {
                if(to==p) continue;
                go(to,a,val*mi(x)/mi(y));
            }
        };
        go(1,0,one);
        cout << res << "\n";
    }
    return 0;
}