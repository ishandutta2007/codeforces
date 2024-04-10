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
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll b,q,y,c,r,z;
        cin >> b >> q >> y >> c >> r >> z;
        cout << [&]()->int
        {
            if(r%q) return 0;
            auto in_two=[&](ll e)->bool{return (((e-b)%q)==0&&b<=e&&e<=b+(y-1)*q);};
            ll clast=c+(z-1)*r;
            if(!in_two(c)||!in_two(clast)) return 0;
            if(!in_two(c-r)||!in_two(clast+r)) return -1;
            mi res=0;
            auto go=[&](ll p)
            {
                if(lcm(p,q)!=r) return;
                ll cnt=(r-1)/p+1;
                res+=(mi(cnt)*mi(cnt));
            };
            for(ll i=1;i*i<=r;i++)
            {
                if(r%i) continue;
                go(i);
                if(i*i<r) go(r/i);
            }
            return int(res);
        }() << "\n";
    }
    return 0;
}