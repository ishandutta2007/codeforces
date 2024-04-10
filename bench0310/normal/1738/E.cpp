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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        ll s=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        if(s==0)
        {
            cout << pow(mi(2),n-1) << "\n";
            continue;
        }
        vector<mi> f(n+1,1);
        for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
        vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
        for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
        auto C=[&](int x,int y)->mi{return (f[x]*finv[y]*finv[x-y]);};
        mi res=1;
        auto go=[&](int x,int y)
        {
            mi now=0;
            for(int i=0;i<=min(x,y);i++) now+=(C(x,i)*C(y,i));
            res*=now;
        };
        int l=1,r=n;
        int cl=0,cr=0;
        while(a[l]==0){cl++;l++;}
        while(a[r]==0){cr++;r--;}
        go(cl,cr);
        ll p=a[l++],q=0;
        while(1)
        {
            while(p<q) p+=a[l++];
            if(2*p>s) break;
            while(q<p) q+=a[r--];
            if(2*p<s)            
            {
                if(p==q)
                {
                    cl=0;cr=0;
                    while(a[l]==0){cl++;l++;}
                    while(a[r]==0){cr++;r--;}
                    go(cl+1,cr+1);
                    p+=a[l++];
                }
            }
            else
            {
                res*=pow(mi(2),r-l+2);
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}