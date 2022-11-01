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

const int N=200005;
vector<array<int,2>> trie(30*N,{-1,-1});
vector<bool> ini(30*N,0);
vector<bool> opt(30*N,0);
int tcnt=0;
vector<mi> f(N,0);
vector<mi> s(N,0);
mi res=0;
int p;

void add(int a)
{
    int x=0;
    for(int j=29;j>=0;j--)
    {
        int b=((a>>j)&1);
        if(x==0&&b==0) continue;
        if(trie[x][b]==-1) trie[x][b]=(++tcnt);
        x=trie[x][b];
    }
    ini[x]=1;
}

void go(int a,int d)
{
    if(d>p) return;
    if(ini[a]&&!opt[a])
    {
        res+=s[p-d];
        opt[a]=1;
    }
    if(opt[a])
    {
        if(trie[a][0]!=-1&&trie[trie[a][0]][0]!=-1) opt[trie[trie[a][0]][0]]=1;
        if(trie[a][1]!=-1) opt[trie[a][1]]=1;
    }
    for(int j=0;j<2;j++) if(trie[a][j]!=-1) go(trie[a][j],d+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> p;
    f[0]=f[1]=1;
    for(int i=2;i<=p;i++) f[i]=f[i-1]+f[i-2];
    s[0]=1;
    for(int i=1;i<=p;i++) s[i]=s[i-1]+f[i];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        add(a);
    }
    go(0,0);
    cout << res << "\n";
    return 0;
}