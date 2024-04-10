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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> cnt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            cnt[a]++;
        }
        vector<int> v;
        int g=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>0)
            {
                v.push_back(cnt[i]);
                g=gcd(g,cnt[i]);
            }
        }
        vector<mi> f(n+1,1);
        for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
        vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
        for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
        vector<int> sieve(n+1,0);
        for(int i=1;i<=n;i++) sieve[i]=i;
        vector<int> phi(n+1,1);
        for(int i=2;i<=n;i++)
        {
            int p=sieve[i];
            if(i==p) phi[i]=p-1;
            else if(sieve[i/p]==p) phi[i]=phi[i/p]*p;
            else phi[i]=phi[i/p]*(p-1);
            if(i<=n/i) for(int j=i*i;j<=n;j+=i) if(sieve[j]==j) sieve[j]=i;
        }
        mi res=1;
        if(g<n)
        {
            mi num=0,den=0;
            for(int one=1;one<=g;one++)
            {
                if(g%one) continue;
                int cycles=n/one;
                mi now=f[cycles];
                vector<int> u;
                for(int a:v) u.push_back(a/one);
                for(int a:u) now*=finv[a];
                den+=(phi[n/cycles]*now);
                for(int a:u)
                {
                    if(a>=2)
                    {
                        num+=(now*finv[cycles]*f[cycles-2]*f[a]*finv[a-2]*cycles*phi[n/cycles]*(n/cycles));
                    }
                }
            }
            num=(den*n-num);
            res=(num/n)/(den/n);
        }
        cout << res << "\n";
    }
    return 0;
}