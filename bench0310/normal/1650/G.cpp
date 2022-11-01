#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1000000007;

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
        int n,m;
        cin >> n >> m;
        int s,t;
        cin >> s >> t;
        vector<int> v[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> d(n+1,-1);
        d[s]=0;
        queue<int> q;
        q.push(s);
        vector<int> ord;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            ord.push_back(a);
            for(int to:v[a]) if(d[to]==-1) {d[to]=d[a]+1; q.push(to);}
        }
        vector<mi> one(n+1,0);
        one[s]=1;
        for(int a:ord)
        {
            for(int from:v[a]) if(d[from]+1==d[a]) one[a]+=one[from];
        }
        ranges::reverse(ord);
        vector<mi> two(n+1,0);
        two[t]=1;
        for(int a:ord)
        {
            for(int to:v[a]) if(d[a]+1==d[to]) two[a]+=two[to];
        }
        mi res=one[t];
        for(int i=1;i<=n;i++)
        {
            for(int to:v[i]) if(d[i]==d[to]) res+=(one[i]*two[to]);
        }
        cout << res << "\n";
    }
    return 0;
}