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
    string a;
    cin >> a;
    int n=a.size();
    mi zero=0,one=0;
    mi prv=0;
    int l=0;
    stack<pair<mi,int>> s;
    while(l<n)
    {
        int r=l;
        while(r+1<n&&a[r+1]==a[l]) r++;
        int cnt=r-l+1;
        if(a[l]=='1')
        {
            mi now=(zero+one-prv);
            if(s.empty()) now++;
            one+=(cnt*now);
            prv=(zero+one-now);
            s.push({cnt*now,0});
        }
        else
        {
            if(s.empty()) zero+=cnt;
            else
            {
                mi sum=0;
                while(!s.empty()&&s.top().second<=cnt)
                {
                    auto [o,c]=s.top();
                    s.pop();
                    zero+=((cnt-c)*o);
                    sum+=o;
                }
                s.push({sum,cnt});
            }
        }
        l=r+1;
    }
    if(s.empty()) cout << n << "\n";
    else
    {
        mi e=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]=='0') e++;
            else break;
        }
        cout << (e+1)*one << "\n";
    }
    return 0;
}