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
    int q;
    cin >> q;
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        s="$"+s;
        int n=s.size();
        int m=t.size();
        vector<int> occ(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i+m-1>n) occ[i]=0;
            else
            {
                bool ok=1;
                for(int j=0;j<m;j++) ok&=(s[i+j]==t[j]);
                occ[i]=ok;
            }
        }
        vector<int> nxt(n+2,0);
        nxt[n+1]=n+1;
        for(int i=n;i>=1;i--)
        {
            nxt[i]=nxt[i+1];
            if(occ[i]==1) nxt[i]=i;
        }
        auto cool=[&](int l,int r)->bool{return (nxt[l]+m-1>r);};
        vector dp(n+1,vector(n+1,mi(0)));
        vector ok(n+1,vector(n+1,bool(0)));
        dp[0][0]=1;
        ok[0][0]=1;
        int opt=n+1;
        if(cool(1,n)) opt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int p=0;p<i-m+1;p++)
                {
                    if(i-m+1>=1&&occ[i-m+1]==1&&cool(p+1,i-m)&&ok[p][j-1])
                    {
                        dp[i][j]+=dp[p][j-1];
                        ok[i][j]=1;
                        if(cool(i+1,n)) opt=min(opt,j);
                    }
                }
            }
        }
        mi res=0;
        for(int i=0;i<=n;i++) if(ok[i][opt]&&cool(i+1,n)) res+=dp[i][opt];
        cout << opt << " " << res << "\n";
    }
    return 0;
}