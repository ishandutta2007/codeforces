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
    int n,a,x,y,k,m;
    cin >> n >> a >> x >> y >> k >> m;
    int sz=1;
    for(int i=1;i<=k-1;i++) sz=lcm(sz,i);
    vector<mi> e(sz,0);
    mi res=0;
    mi inv_n=inv(mi(n));
    for(int i=0;i<n;i++)
    {
        res+=(mi((a/sz)*sz)*inv_n*k);
        e[a%sz]++;
        a=(ll(x)*a+y)%m;
    }
    for(int i=1;i<=k;i++)
    {
        vector<mi> ne(sz,0);
        for(int j=0;j<sz;j++)
        {
            res+=(e[j]*j*inv_n);
            ne[j]+=(mi(n-1)*inv_n*e[j]);
            ne[j-(j%i)]+=(inv_n*e[j]);
        }
        e=ne;
    }
    cout << res*pow(mi(n),k) << "\n";
    return 0;
}