#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);};
const int N=1000000;
const int S=2;
const array<ll,S> p={31,rng(32,81)};
const array<ll,S> mod={1000000007,1000000009};
vector<array<ll,S>> pw(N+1);

struct h
{
    array<ll,S> a;
    int sz;
    h(){a.fill(0);sz=0;}
    h(char c)
    {
        a.fill(c-'a');
        sz=1;
    }
    friend h operator+(const h &a,const h &b)
    {
        h c;
        for(int j=0;j<S;j++) c.a[j]=(a.a[j]*pw[b.sz][j]+b.a[j])%mod[j];
        c.sz=a.sz+b.sz;
        return c;
    }
    friend h operator-(const h &a,const h &b)
    {
        h c;
        for(int j=0;j<S;j++) c.a[j]=(a.a[j]-(b.a[j]*pw[a.sz-b.sz][j])%mod[j]+mod[j])%mod[j];
        c.sz=a.sz-b.sz;
        return c;
    }
    friend bool operator==(const h &a,const h &b){return (a.a==b.a&&a.sz==b.sz);}
};

const ll mmod=1000000007;
ll add(ll a,ll b){return (a+b)%mmod;}
ll sub(ll a,ll b){return (a-b+mmod)%mmod;}

struct str
{
    int n;
    string s;
    vector<h> f;
    vector<int> gl;
    vector<int> gr;
    vector<ll> dp;
    vector<ll> all;
    vector<ll> good;
    str(string t)
    {
        n=t.size();
        s="$"+t+"$";
        f.assign(n+1,h());
        for(int i=1;i<=n;i++) f[i]=f[i-1]+h(s[i]);
        gl.assign(n+1,0);
        for(int i=1;i<=n;i++) gl[i]=(s[i]==s[i-1]?gl[i-1]:i);
        gr.assign(n+2,0);
        for(int i=n;i>=1;i--) gr[i]=(s[i]==s[i+1]?gr[i+1]:i);
        dp.assign(n+1,0);
        all.assign(n+1,0);
        good.assign(n+1,0);
    }
    void calc()
    {
        for(int i=1;i<=n;i++) all[i]=add(all[i-1],dp[i]);
        for(int i=1;i<=n;i++)
        {
            good[i]=good[i-1];
            int t=gr[i]+1;
            if(t<=n&&s[i]>s[t]) good[i]=add(good[i],dp[i]);
        }
    }
    ll sum_all(int l,int r){return sub(all[r],all[l-1]);}
    ll sum_good(int l,int r){return sub(good[r],good[l-1]);}
    h g(int m,int r)
    {
        if(r==0||m<r) return f[m];
        else return f[r-1]+(f[m+1]-f[r]);
    }
    char mth(int m,int r)
    {
        if(r==0) return (m<=n?s[m]:'0');
        if(m<r) return s[m];
        else if(m+1<=n) return s[m+1];
        else return '0';
    }
    friend int lcp(str &a,int ra,str &b,int rb)
    {
        int tl=0,tr=min(a.n-(ra!=0),b.n-(rb!=0))+1;
        while(tl<tr-1)
        {
            int m=(tl+tr)/2;
            if(a.g(m,ra)==b.g(m,rb)) tl=m;
            else tr=m;
        }
        return tl;
    }
    friend bool ok(str &a,int ra,str &b,int rb)
    {
        int l=lcp(a,ra,b,rb);
        char x=a.mth(l+1,ra);
        char y=b.mth(l+1,rb);
        if(x=='1') x='0';
        if(y=='1') y='0';
        return (x<=y);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0].fill(1);
    for(int i=1;i<=N;i++) for(int j=0;j<S;j++) pw[i][j]=(pw[i-1][j]*p[j])%mod[j];
    int q;
    cin >> q;
    str a("1");
    a.dp[1]=1;
    a.calc();
    while(q--)
    {
        string s;
        cin >> s;
        s+="1";
        str b(s);
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            ll opt=0;
            int l=lcp(a,0,b,i);
            char x=a.mth(l+1,0);
            char y=b.mth(l+1,i);
            if(x!='0')
            {
                if(x<y) opt=add(opt,a.sum_all(l+2,a.n));
                if(ok(a,l+1,b,i)) opt=add(opt,a.dp[l+1]);
            }
            if(l>=1)
            {
                int g=a.gl[l];
                opt=add(opt,a.sum_good(1,g-1));
                if(ok(a,l,b,i)) opt=add(opt,a.sum_all(g,l));
            }
            b.dp[i]=opt;
        }
        b.calc();
        a=b;
    }
    cout << a.sum_all(1,a.n) << "\n";
    return 0;
}