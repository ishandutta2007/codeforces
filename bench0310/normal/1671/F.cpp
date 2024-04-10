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
    const int S=11;
    vector one(S+2,vector(S+1,vector(S+1,mi(0)))); //sz,k,x
    for(int sz=2;sz<=S+1;sz++)
    {
        vector dp((1<<sz),vector(sz,vector(S+1,vector(S+1,mi(0))))); //m,prv,k,x
        dp[0][0][0][0]=1;
        for(int m=0;m<(1<<sz)-1;m++)
        {
            int c=popcount(uint32_t(m));
            bool bad=1;
            for(int i=0;i<c;i++) bad&=((m>>i)&1);
            if(c>0&&bad) continue;
            vector<int> sum(sz+1,0);
            for(int i=sz-1;i>=0;i--) sum[i]=sum[i+1]+((m>>i)&1);
            for(int p=0;p<sz;p++)
            {
                for(int k=0;k<=S;k++)
                {
                    for(int x=0;x<=S;x++)
                    {
                        for(int b=0;b<sz;b++)
                        {
                            if(m&(1<<b)) continue;
                            int nk=k+sum[b+1];
                            int nx=x+(p>b);
                            if(nk<=S&&nx<=S) dp[m^(1<<b)][b][nk][nx]+=dp[m][p][k][x];
                        }
                    }
                }
            }
        }
        for(int k=0;k<=S;k++) for(int x=0;x<=S;x++) for(int p=0;p<sz;p++) one[sz][k][x]+=dp[(1<<sz)-1][p][k][x];
    }
    vector<mi> f(S+1,1);
    for(int i=1;i<=S;i++) f[i]=f[i-1]*mi(i);
    vector<mi> finv(S+1,1); finv[S]=inv(f[S]);
    for(int i=S;i>=1;i--) finv[i-1]=finv[i]*mi(i);
    auto C=[&](int a,int b)->mi{return (f[a]*finv[b]*finv[a-b]);};
    vector cnt(2*S+1,vector(S+1,vector(S+1,vector(S+1,mi(0))))); //total,c,k,x
    cnt[0][0][0][0]=1;
    for(int sz=2;sz<=S+1;sz++)
    {
        for(int tk=0;tk<=S;tk++)
        {
            for(int tx=0;tx<=S;tx++)
            {
                mi now=one[sz][tk][tx];
                if(now==0) continue;
                vector<mi> pw(S+1,1);
                for(int i=1;i<=S;i++) pw[i]=pw[i-1]*now;
                for(int total=2*S-sz;total>=0;total--)
                {
                    for(int c=0;c<=S-1;c++)
                    {
                        for(int k=0;k<=S-tk;k++)
                        {
                            for(int x=0;x<=S-tx;x++)
                            {
                                for(int t=1;total+sz*t<=2*S&&c+t<=S&&k+t*tk<=S&&x+t*tx<=S;t++)
                                {
                                    cnt[total+t*sz][c+t][k+t*tk][x+t*tx]+=(cnt[total][c][k][x]*C(c+t,t)*pw[t]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,k,x;
        cin >> n >> k >> x;
        mi res=0;
        for(int total=0;total<=min(2*S,n);total++)
        {
            for(int c=0;c<=S;c++)
            {
                int a=(n-total);
                int o=c+a;
                mi now=cnt[total][c][k][x];
                for(int i=o;i>a;i--) now*=mi(i);
                now*=finv[o-a];
                res+=now;
            }
        }
        cout << res << "\n";
    }
    return 0;
}