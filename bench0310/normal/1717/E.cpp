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
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sieve(n+1,1);
    vector<int> phi(n+1,1);
    for(int i=1;i<=n;i++) phi[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(!sieve[i]) continue;
        for(int j=i;j<=n;j+=i)
        {
            sieve[j]=0;
            phi[j]/=i;
            phi[j]*=(i-1);
        }
    }
    mi res=0;
    vector<array<int,2>> v;
    for(int i=1;i<=n-1;i++) for(int j=2*i;j<=n-1;j+=i) v.push_back({j,i});
    ranges::sort(v);
    int sz=v.size();
    int l=0;
    while(l<sz)
    {
        int r=l;
        while(r+1<sz&&v[r+1][0]==v[l][0]) r++;
        int s=v[l][0];
        int c=n-s;
        for(int i=l;i<=r;i++)
        {
            int d=v[i][1];
            ll t=lcm(ll(c),ll(d));
            res+=(mi(t)*mi(phi[s/d]));
        }
        l=r+1;
    }
    cout << res << "\n";
    return 0;
}