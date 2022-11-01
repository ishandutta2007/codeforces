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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<array<int,2>> v[n+1];
        vector<int> a(n+1,0);
        vector<int> p(n+1,0);
        vector<int> b(n+1,0);
        vector<int> s(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            a[x]=i;
        }
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++)
        {
            int c;
            cin >> c;
            p[i]=a[b[i]];
            s[i]=(c!=0);
        }
        mi res=1;
        vector<bool> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int x=i;
            int r=0;
            int cnt=0;
            while(!vis[x])
            {
                r|=s[x];
                vis[x]=1;
                x=p[x];
                cnt++;
            }
            if(r==0&&cnt>1) res*=2;
        }
        cout << res << "\n";
    }
    return 0;
}