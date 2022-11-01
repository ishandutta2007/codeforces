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
    string s;
    cin >> s;
    s="$"+s;
    const int N=17;
    vector<mi> res(1<<N,0);
    int qcnt=ranges::count(s,'?');
    for(int p=1;p<=N;p++)
    {
        vector<mi> pw(n+1,1);
        for(int i=1;i<=n;i++) pw[i]=pw[i-1]*mi(p);
        vector<mi> dp(1<<N,0);
        auto go=[&](int l,int r)
        {
            int qnow=0;
            int c=0;
            int m=0;
            while(l>=1&&r<=n)
            {
                if(s[l]=='?'&&s[r]=='?') c++;
                else if(s[l]=='?'||s[r]=='?') m|=(1<<((s[l]!='?'?s[l]:s[r])-'a'));
                else if(s[l]!=s[r]) break;
                qnow+=(s[l]=='?');
                qnow+=(s[r]=='?');
                qnow-=(s[l]=='?'&&l==r);
                dp[m]+=pw[c+qcnt-qnow];
                l--; r++;
            }
        };
        for(int i=1;i<=n;i++)
        {
            go(i,i);
            if(i+1<=n) go(i,i+1);
        }
        for(int i=0;i<N;i++) for(int m=0;m<(1<<N);m++) if(m&(1<<i)) dp[m]+=dp[m^(1<<i)];
        for(int m=0;m<(1<<N);m++) if(popcount(uint32_t(m))==p) res[m]=dp[m];
    }
    int q;
    cin >> q;
    while(q--)
    {
        string t;
        cin >> t;
        int m=0;
        for(char c:t) m^=(1<<(c-'a'));
        cout << res[m] << "\n";
    }
    return 0;
}