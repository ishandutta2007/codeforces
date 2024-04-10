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
    int n;
    cin >> n;
    int m=(1<<n)-1;
    string s;
    cin >> s;
    s="$"+s;
    vector<int> id(m+1,0);
    for(int i=(1<<(n-1));i<=m;i++) id[i]=(s[i]-'0');
    int now=1;
    map<array<int,3>,int> t;
    auto f=[&](int c,int a,int b)->int
    {
        if(a>b) swap(a,b);
        if(t.contains({c,a,b})) return t[{c,a,b}];
        else return (t[{c,a,b}]=(++now));
    };
    vector<mi> dp(m+1,1);
    for(int i=m/2;i>=1;i--)
    {
        id[i]=f(s[i]-'0',id[2*i],id[2*i+1]);
        if(s[2*i]==s[2*i+1]&&id[2*i]==id[2*i+1]) dp[i]=dp[2*i]*dp[2*i];
        else dp[i]=mi(2)*dp[2*i]*dp[2*i+1];
    }
    cout << dp[1] << "\n";
    return 0;
}