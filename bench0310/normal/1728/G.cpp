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
    mi d;
    int n,m;
    cin >> d >> n >> m;
    vector<int> l(n);
    for(int &x:l) cin >> x;
    vector<int> p(m);
    for(int &x:p) cin >> x;
    ranges::sort(p);
    vector mid(m,vector(m,mi(1)));
    vector<mi> left(m,1);
    vector<mi> right(m,1);
    for(int i=0;i<m;i++)
    {
        for(int x:l)
        {
            if(x<p[i]) left[i]*=(p[i]-x);
            if(p[i]<x) right[i]*=(x-p[i]);
        }
        for(int j=i+1;j<m;j++)
        {
            for(int x:l)
            {
                if(p[i]<x&&x<p[j]) mid[i][j]*=min(x-p[i],p[j]-x);
            }
        }
    }
    vector<mi> dp(1<<m,1);
    vector summit(m,vector(m,mi(0))); //summid, but summit looks cooler
    vector<mi> sumleft(m,0);
    vector<mi> sumright(m,0);
    for(int mask=1;mask<(1<<m);mask++)
    {
        vector<int> b;
        for(int i=0;i<m;i++) if(mask&(1<<i)) b.push_back(i);
        int pc=b.size();
        dp[mask]*=(left[b[0]]*right[b[pc-1]]);
        for(int i=0;i+1<pc;i++) dp[mask]*=mid[b[i]][b[i+1]];
        if(pc&1) dp[mask]*=mi(-1);
        sumright[b[0]]+=dp[mask];
        sumleft[b[pc-1]]+=dp[mask];
        for(int i=0;i+1<pc;i++) summit[b[i]][b[i+1]]+=dp[mask];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int f;
        cin >> f;
        int lim=0;
        while(lim<m&&p[lim]<f) lim++;
        mi res=pow(d+1,n+1);
        for(int i=0;i<lim;i++) res+=(sumleft[i]*(f-p[i]));
        for(int i=lim;i<m;i++) res+=(sumright[i]*(p[i]-f));
        for(int i=0;i<lim;i++)
        {
            for(int j=lim;j<m;j++)
            {
                res+=(summit[i][j]*min(f-p[i],p[j]-f));
            }
        }
        cout << res << "\n";
    }
    return 0;
}