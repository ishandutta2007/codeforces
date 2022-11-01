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

struct ft
{
    int n;
    vector<mi> tree;
    ft(int _n):n(_n+1){tree.resize(n);}
    void upd(int idx,mi x){for(;idx<n;idx=(idx|(idx+1)))tree[idx]+=x;}
    mi sum(int p){mi r=0; for(;p>=0;p=(p&(p+1))-1)r+=tree[p]; return r;}
    mi qry(int l,int r){return (sum(r)-(l>0?sum(l-1):0));}
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
        vector<array<int,2>> e(n);
        for(int i=0;i<n;i++)
        {
            cin >> e[i][0];
            e[i][1]=i+1;
        }
        ranges::sort(e);
        vector<int> a(n+1,0);
        int id=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&e[i][0]!=e[i-1][0]) id++;
            a[e[i][1]]=id;
        }
        ft cnt(n);
        ft all(n);
        vector<mi> one(n+1,0);
        for(int i=1;i<=n;i++)
        {
            mi c=cnt.qry(1,a[i]-1);
            mi s=all.qry(1,a[i]-1);
            one[i]=s+c+1;
            cnt.upd(a[i],c+1);
            all.upd(a[i],s+c+1);
        }
        mi res=0;
        vector<int> local_maxima;
        ft two(n);
        ft maximum_cnt(n);
        for(int i=n;i>=1;i--)
        {
            if(local_maxima.empty()||a[i]>local_maxima.back()) local_maxima.push_back(a[i]);
            if(local_maxima.back()==a[i]) maximum_cnt.upd(a[i],1);
            else
            {
                int u=*ranges::upper_bound(local_maxima,a[i]);
                //merger
                res+=one[i];
                res+=one[i]*(two.qry(u,n)+maximum_cnt.qry(u,n)-1);
                //extend
                two.upd(a[i],two.qry(a[i]+1,u-1)+1);
            }
        }
        cout << res << "\n";
    }
    return 0;
}