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
    vector<int> a(n+1,0);
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int b;
        cin >> b;
        a[b]++;
        c[a[b]]++;
    }
    vector dp(n+1,vector(n+1,mi(0))); //mx,sum
    dp[n][0]=1;
    mi res=0;
    for(int i=1;i<=n;i++)
    {
        //sum dp
        for(int s=0;s<=n;s++)
        {
            for(int j=(n/max(1,i-1))-1;j>=1;j--) dp[j][s]+=dp[j+1][s];
        }
        //transition to ndp
        c[i]+=c[i-1];
        vector ndp((n/i)+1,vector(n+1,mi(0)));
        for(int j=1;j<=n/i;j++)
        {
            for(int s=j;s<=c[i];s++)
            {
                ndp[j][s]=dp[j][s-j];
            }
            res+=ndp[j][n];
        }
        dp=ndp;
    }
    cout << res << "\n";
    return 0;
}