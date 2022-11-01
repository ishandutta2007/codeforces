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
    const int N=100000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    vector<mi> phi(N+1,1);
    for(int i=2;i<=N;i++)
    {
        int p=sieve[i];
        if(p==i) phi[i]=p-1;
        else if((i/p)%p) phi[i]=phi[p]*phi[i/p];
        else phi[i]=mi(p)*phi[i/p];
        if(i<=N/i) for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<int> d[N+1];
    for(int i=1;i<=N;i++) for(int j=i;j<=N;j+=i) d[j].push_back(i);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<mi> cnt(N+1,0);
    mi res=0;
    for(int r=1;r<=n;r++)
    {
        vector<int> t;
        for(int j=r;j<=n;j+=r)
        {
            for(int l:d[a[j]])
            {
                cnt[l]++;
                t.push_back(l);
            }
        }
        for(int l:t)
        {
            res+=(phi[r]*phi[l]*cnt[l]*cnt[l]);
            cnt[l]=0;
        }
    }
    cout << res << "\n";
    return 0;
}