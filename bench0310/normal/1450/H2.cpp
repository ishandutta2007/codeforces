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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s="$"+s;
    int x=n/2;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        x-=(((i%2)==1&&s[i]=='w')+((i%2)==0&&s[i]=='b'));
        f+=(s[i]=='?');
    }
    vector<array<int,4>> e[n+1]; //l,r,k,id
    auto add_one=[&](int u,int l,int r,int k,int id)
    {
        if(u>=0&&l<=r)
        {
            l=max(l,0);
            r=min(r,u);
            e[u].push_back({l,r,k,id});
        }
    };
    vector<mi> all(m+1,0);
    vector<mi> res(m+1,0);
    vector<mi> fact(n+1,1);
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*mi(i);
    vector<mi> finv(n+1,1); finv[n]=inv(fact[n]);
    for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
    auto c=[&](int a,int b)->mi
    {
        if(!(0<=b&&b<=a)) return 0;
        return (fact[a]*finv[b]*finv[a-b]);
    };
    auto add=[&](int q)
    {
        all[q]=(1/pow(mi(2),f));
        if(f==1) res[q]=mi(abs(x-(x&1)));
        else
        {
            int ft=f-((f-x)&1);
            add_one(f-1,0,x-2,x,q);
            add_one(f-2,0,x-3,-f,q);
            add_one(f-2,x,ft-1,f,q);
            add_one(f-1,x+1,ft,-x,q);
        }
    };
    add(0);
    for(int i=1;i<=m;i++)
    {
        int p;
        char a;
        cin >> p >> a;
        f-=(s[p]=='?');
        x+=(((p%2)==1&&s[p]=='w')+((p%2)==0&&s[p]=='b'));
        s[p]=a;
        f+=(s[p]=='?');
        x-=(((p%2)==1&&s[p]=='w')+((p%2)==0&&s[p]=='b'));
        add(i);
    }
    const int S=450;
    vector<mi> v;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<(int)v.size();j++) v[j]=(2*v[j]+c(i-1,j*S-1)-c(i-1,(j+1)*S-1));
        if(((i+1)%S)==0)
        {
            mi t=0;
            for(int j=0;j<S;j++) t+=c(i,i-j);
            v.push_back(t);
        }
        auto sum_one=[&](int p)->mi
        {
            mi r=0;
            int j=0;
            for(;(j+1)*S-1<=p;j++) r+=v[j];
            for(int a=j*S;a<=p;a++) r+=c(i,a);
            return r;
        };
        auto sum=[&](int l,int r)->mi{return (sum_one(r)-(l>0?sum_one(l-1):0));};
        for(auto [l,r,k,id]:e[i]) res[id]+=(mi(k)*sum(l,r));
    }
    for(int i=0;i<=m;i++) cout << res[i]*all[i] << "\n";
    return 0;
}