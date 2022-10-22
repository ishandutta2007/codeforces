#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

string s,t;
int n,q;
int nex[MAXN/10+5][26];
ll f[MAXN/10+5][26];
ll p2[MAXN];
ll ip2[MAXN];

ll aux1(int act,int lim,int sz)
{
//    cout << act << ' ' << lim << ' ' << sz << '\n';
    ll prox=min(lim,nex[act][t[act]-'a']);
    ll ts=lim-prox;
    ll nt=(f[lim][t[act]-'a']-((f[prox][t[act]-'a']*p2[lim-prox])%mod)+mod)%mod;
    prox-=act;
    ll sum=0;
    if(prox>=23 || p2[prox]>=sz)
        sum=(sum+(((p2[prox]-sz+mod)%mod)*p2[ts])%mod)%mod;
    if(prox>=23 || p2[prox+1]>=sz)
        sum=(sum+(((min(p2[prox+1]-sz,(ll)sz)+mod)%mod)*nt)%mod)%mod;
    return sum;
}

ll aux2(int act,int lim,int c)
{
    return (f[lim][c]-((f[act][c]*p2[lim-act])%mod)+mod)%mod;
}

ll solve(string& w,int lim,int act)
{
//    cout << w << ' ' << lim << ' ' << act << '\n';
    if(lim==act)
        return 0;
    int sz=w.size();
//    db(sz)
    bool ok=(w[0]==t[act]);
    for(int i=1;i<sz;i++)
        ok&=(w[0]==w[i]);
    if(ok && sz!=1)
        return aux1(act,lim,sz);
    if(sz==1)
        return aux2(act,lim,w[0]-'a');

    bool kk[2];
    kk[0]=(w[0]==t[act]);
    kk[1]=(w[1]==t[act]);
    for(int i=2;i<sz;i++)
        kk[i&1]&=(w[i]==w[i&1]);
    if(kk[0])
    {
//        db(0)
        int len=sz/2;
        string to_solve(len,' ');
        for(int i=1;i<sz;i+=2)
            to_solve[i/2]=w[i];
        return solve(to_solve,lim,act+1);
    }
    if(kk[1])
    {
//        db(1)
        int len=(sz-1)/2+1;
        string to_solve(len,' ');
        for(int i=0;i<sz;i+=2)
            to_solve[i/2]=w[i];
        return solve(to_solve,lim,act+1);
    }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);
//    freopen(".in","w",stdout);
//
//    mt19937 rng(time(0));
//    int n=10,q=1000;
//    int sz=4;
//    string s(sz,' ');
//    string t(n,' ');
//    for(int i=0;i<sz;i++)
//    {
//        int v=rng();
//        s[i]=(abs(v)&1)+'a';
//    }
//    for(int i=0;i<n;i++)
//    {
//        int v=rng();
//        t[i]=(abs(v)&1)+'a';
//    }
//    cout << n << ' ' << q << '\n';
//    db(s)
//    db(t)
//    for(int i=0;i<q;i++)
//    {
//        int k=rng();
//        k=abs(k)%(n+1);
//        int len=rng();
//        len=abs(len)%10+1;
//        string qs(len,' ');
//        for(int j=0;j<len;j++)
//        {
//            int v=rng();
//            qs[j]=(abs(v)&1)+'a';
//        }
//        cout << k << ' ' << qs << '\n';
//    }

    p2[0]=ip2[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        p2[i]=(p2[i-1]*2)%mod;
        ip2[i]=(ip2[i-1]*(ll)((mod+1)/2))%mod;
    }

    cin >> n >> q;
    cin >> s >> t;
    for(int i=0;i<26;i++)
        nex[n][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            nex[i][j]=i;
        nex[i][t[i]-'a']=nex[i+1][t[i]-'a'];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
            f[i+1][j]=(f[i][j]*2)%mod;
        f[i+1][t[i]-'a']=(f[i+1][t[i]-'a']+1)%mod;
    }

    int l=s.size();
    vector<int> xxxs;
    for(int qs=0;qs<q;qs++)
    {
        int k;
        cin >> k;
        string w;
        cin >> w;
        ll res=0;
        int sz=w.size();
        for(int i=0;i<=l;i++)
        {
            if(sz<=l-i)
            {
//                db("xxx1")
//                db(i)
                bool ok=1;
                for(int j=0;j<sz;j++)
                    ok&=(s[i+j]==w[j]);
                if(ok)
                {
                    res=(res+p2[k])%mod;
//                    db("ok")
                }
            }
            else
            {

//                db("xxx2")
//                db(i)
                int len=((sz-(l-i))-1)/(l+1)+1;
                string to_solve(len,' ');
                bool ok=1;
                for(int j=0;j<sz;j++)
                {
                    int p=(i+j)%(l+1);
                    if(p==l)
                        to_solve[j/(l+1)]=w[j];
                    else
                        ok&=(s[p]==w[j]);
                }

//                cout << to_solve << ' ' << k << ' ' << ok << '\n';
                if(ok)
                {
                    ll v=solve(to_solve,k,0);
//                    db(v)
                    res=(res+v)%mod;
                }
//                db("")
            }
        }
//        db("ans")
        db(res)

//        ///check
//        string ss=s;
//        for(int i=0;i<k;i++)
//        {
//            ss.push_back(t[i]);
//            ss=ss+ss;
//            ss.pop_back();
//        }
//
//        ll r2=0;
//        for(int i=0;i+w.size()<=ss.size();i++)
//        {
//            bool ok=1;
//            for(int j=0;j<w.size();j++)
//                ok&=(w[j]==ss[i+j]);
//            r2+=ok;
//        }
//        if(r2!=res)
//        {
////            cout << qs << ' ' << res << ' ' << r2 << '\n';
////            xxxs.push_back(qs);
//        }
    }

//    db("xxx")
//    for(auto y : xxxs)
//        db(y)

    return 0;
}
/**
4 3
aba
bbac
3 ab
2 bab
4 aba

6 6
aa
bbaabb
1 aaaab
2 aaaab
3 aaaab
4 aaaab
5 aaaab
6 aaaab

6 6
aa
bbccbb
1 abaab
2 abaab
3 acaabaa
4 abaabaa
5 acaabaac
6 acaabaabaa

6 1
aa
bbccbb
5 acaabaac

6 6
aaa
aaaabc
1 aaaa
2 aaaaa
3 aaaaaa
4 aaaaaaa
5 aaaaaaaa
6 aaaaaaaaa

10 1
bbaa
aaaabbabba
8 aabbaaa
**/