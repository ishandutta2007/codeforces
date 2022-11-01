#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int n;
    string s;
    ll mod;
    vector<ll> h;
    vector<ll> pw;
    ll y;
    ll add(ll a,ll b){return (a+b)%mod;}
    ll sub(ll a,ll b){return (a-b+mod)%mod;}
    ll mul(ll a,ll b){return (a*b)%mod;}
    void ini(string t,string x,ll m)
    {
        s="$"+t;
        n=t.size();
        mod=m;
        h.assign(n+1,0);
        pw.assign(n+1,1);
        for(int i=1;i<=n;i++) pw[i]=mul(pw[i-1],10);
        for(int i=1;i<=n;i++) h[i]=add(mul(10,h[i-1]),s[i]-'0');
        y=0;
        for(char c:x) y=add(mul(10,y),c-'0');
    }
    ll g(int l,int r){return sub(h[r],mul(pw[r-l+1],h[l-1]));}
    bool in(int l,int r){return (1<=l&&r<=n);}
    bool ok(int l1,int r1,int l2,int r2){return (in(l1,r1)&&in(l2,r2)&&add(g(l1,r1),g(l2,r2))==y);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,x;
    cin >> s >> x;
    string t=x+"$"+s;
    int n=s.size();
    int m=x.size();
    int len=t.size();
    vector<int> z(len,0);
    for(int i=1,l=0,r=0;i<len;i++)
    {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<len&&t[z[i]]==t[i+z[i]]) z[i]++;
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    const int C=10;
    vector<obj> v(C);
    for(int i=0;i<C;i++) v[i].ini(s,x,rng(1000000007,2000000000));
    auto go=[&](int p,int a,int b)
    {
        if(a<=0||b<=0) return;
        int l1=p,r1=p+a-1,l2=p+a,r2=p+a+b-1;
        bool ok=1;
        for(int i=0;i<C;i++) ok&=v[i].ok(l1,r1,l2,r2);
        if(ok)
        {
            cout << l1 << " " << r1 << " " << "\n";
            cout << l2 << " " << r2 << " " << "\n";
            exit(0);
        }
    };
    for(int i=1;i<=n;i++)
    {
        go(i,m-1,m-1);
        int a=z[m+i];
        go(i-(m-a),m-a,m);
        go(i-(m-a-1),m-a-1,m);
        go(i,m,m-a);
        go(i,m,m-a-1);
    }
    return 0;
}