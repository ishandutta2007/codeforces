#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r) {return uniform_int_distribution<int>(l,r)(gen);}

const int N=500005;
array<ll,2> p;
const ll mod=1000000007;
int n;
vector<array<ll,2>> pw(N,{1,1});
vector<array<ll,2>> t(N,{0,0});
string s;
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}

struct obj
{
    int sz;
    vector<array<ll,2>> h;
    void ini(int nsz)
    {
        sz=nsz;
        int cnt=0;
        h.push_back({0,0});
        while(cnt+sz<=n)
        {
            cnt+=sz;
            auto r=h.back();
            array<ll,2> nr={0,0};
            for(int j=0;j<2;j++) nr[j]=add(mul(r[j],pw[sz][j]),t[sz][j]);
            h.push_back(nr);
        }
    }
    array<ll,2> geth(int len)
    {
        int whole=(len/sz);
        int rem=(len%sz);
        array<ll,2> r={0,0};
        for(int j=0;j<2;j++) r[j]=add(mul(h[whole][j],pw[rem][j]),t[rem][j]);
        return r;
    }
    char getc(int pos)
    {
        int rem=(pos%sz);
        if(rem==0) rem=sz;
        return s[rem];
    }
};

bool cmp(obj &a,obj &b)
{
    if(a.geth(n)==b.geth(n)) return 0;
    int l=0,r=n;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(a.geth(m)==b.geth(m)) l=m;
        else r=m;
    }
    return (a.getc(l+1)<b.getc(l+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    cin >> s;
    while(n<k)
    {
        s=s+s;
        n*=2;
    }
    if(n>k)
    {
        n=k;
        s=s.substr(0,n);
    }
    p[0]=rng(26,500);
    p[1]=rng(p[0]+1,1000);
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) pw[i][j]=mul(pw[i-1][j],p[j]);
    s="$"+s;
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) t[i][j]=add(mul(t[i-1][j],p[j]),s[i]-'a');
    vector<obj> v(n+1);
    for(int i=1;i<=n;i++) v[i].ini(i);
    int best=1;
    for(int i=2;i<=n;i++) if(cmp(v[i],v[best])) best=i;
    string res;
    while((int)res.size()<n) res+=s.substr(1,best);
    cout << res.substr(0,n) << "\n";
    return 0;
}