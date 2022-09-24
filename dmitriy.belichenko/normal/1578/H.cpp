#pragma GCC optimize("Ofast")

#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define snd second
#define ins insert
//#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
const int MOD1 = 998244353;
const int MOD = 1'000'000'007;
const int INF = 1e9;
const int MaXN = 150;
const int N = 5e5 + 1000;
const int LOG = 25;
const int FACT = 120;
double ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0, (ll) 1e9);
using namespace std;
#define pb push_back
#define SZ 233333
#define int ll
ll qp(ll a,ll b)
{
    ll x=1; a%=MOD;
    while(b)
    {
        if(b&1) x=x*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return x;
}
namespace linear_seq {
    inline vector<int> BM(vector<int> x)
    {
        //ls: (shortest) relation sequence (after filling zeroes) so far
        //cur: current relation sequence
        vector<int> ls,cur;
        //lf: the position of ls (t')
        //ld: delta of ls (v')
        int lf,ld;
        for(int i=0;i<(x.size());++i)
        {
            ll t=0;
            //evaluate at position i
            for(int j=0;j<(cur.size());++j)
                t=(t+x[i-j-1]*(ll)cur[j])%MOD;
            if((t-x[i])%MOD==0) continue; //good so far
            //first non-zero position
            if(!cur.size())
            {
                cur.resize(i+1);
                lf=i; ld=(t-x[i])%MOD;
                continue;
            }
            //cur=cur-c/ld*(x[i]-t)
            ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
            vector<int> c(i-lf-1); //add zeroes in front
            c.pb(k);
            for(int j=0;j<(ls.size());++j)
                c.pb(-ls[j]*k%MOD);
            if(c.size()<cur.size()) c.resize(cur.size());
            for(int j=0;j< (cur.size());++j)
                c[j]=(c[j]+cur[j])%MOD;
            //if cur is better than ls, change ls to cur
            if(i-lf+(int)ls.size()>=cur.size())
                ls=cur,lf=i,ld=(t-x[i])%MOD;
            cur=c;
        }
        for(int i=0;i<(cur.size());++i)
            cur[i]=(cur[i]%MOD+MOD)%MOD;
        return cur;
    }
    int m; //length of recurrence
//a: first terms
//h: relation
    ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
//calculate p*q mod f
    inline void mull(ll*p,ll*q)
    {
        for(int i=0;i<m+m;++i) t_[i]=0;
        for(int i=0;i<m;++i) if(p[i])
                for(int j=0;j<m;++j)
                    t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
        for(int i=m+m-1;i>=m;--i) if(t_[i])
                //miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
                for(int j=m-1;~j;--j)
                    t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
        for(int i=0;i<m;++i) p[i]=t_[i];
    }
    inline ll calc(ll K)
    {
        for(int i=m;~i;--i)
            s[i]=t[i]=0;
        //init
        s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
        //binary-exponentiation
        while(K)
        {
            if(K&1) mull(s,t);
            mull(t,t); K>>=1;
        }
        ll su=0;
        for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
        return (su%MOD+MOD)%MOD;
    }
    inline int work(vector<int> x,ll n)
    {
        if(n<(x.size())) return x[n];
        vector<int> v=BM(x); m=v.size(); if(!m) return 0;
        for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
        return calc(n);
    }
}
using linear_seq::work;
vector<int> ans;
const int P = 3000;
const int T = 14;
ll up;
ll check(ll n) {
    ll ans = 0;
    string st = to_string(n);
    int len = st.size();
    if (n > 0) ans++;
    for (int i = 1; i < T; i++) {
        ll cur = 1, num = n;
        for (int j = 0; j + 1 < i; j++) {
            cur = cur * 10;
            // cur += n % pow(10, j);
        }
        for (int j = len; j < i; j++) num *= 10;
        if (i < len) {
            string pref = "";
            for (int j = 0; j < i; j++) pref += st[j];
            num = stoll(pref);
            num++;
        }
        if (num > up) num = up;
        if (num > cur) ans += num - cur;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    vector<string> s;
//    for (int i = 1; i <= P; i++) {
//        s.push_back(to_string(i));
//        sort(s.begin(), s.end());
//        ll x = 0;
//        for (int j = 0; j < s.size(); j++) {
//            x += (MOD1 - stoi(s[j]) + j + 1) % MOD1;
//            x %= MOD;
//        }
//     //   cout << x << " ";
//        ans.push_back(x);
//    }
//    vector<int> res;
//    for (int i = 0; i < P; i++) res.pb((ans[i] % 1755654) % 310108);
//    set<int> anss;
//    for (int i = 1; i < P; i++) {
//        anss.insert(ans[i]);
//        cout << i << " " << (ans[i] % 1755654) % 310108 << "\n";
//    }
//    cout << anss.size() << "\n";
    ll n;
    cin >> n; n++;
    up = n;
    ll part = n % MOD * (n / MOD1 + 2) % MOD;
    part = MOD - part;
 //   cout << part << "\n";
//    cout << work(res, n) << "\n";
//    cout << work(res, n) << " " << ans[n] << "\n";
//    for (int i = 90; i < 150; i++) {
//        cout << i << " " << work(res, i) - ans[i] << "\n" ;
//    }
    ll ans = 0;
    for (ll i = -n / MOD1 - 1; i <= n / MOD1 + 1; i++ ) {
        ll cur = 0;
        for (int j = 0; j < T; j++) {
            ll L = 0, R = 1;
            if (j >= 1) {
                L = 1;
                for (int k = 0; k + 1 < j; k++) {
                   // if (k >= 1)
                        L *= 10;
                    // else L++;
                }
                R = L * 10;
            }
            if (R > n) R = n;
            ll lastr = R;
            if (L < R) {
                L--;
                while (R - L > 1) {
                    ll mid = (R + L) / 2;
                    if (check(mid) > mid + MOD1 * i - 1) R = mid;
                    else L = mid;
                }
   //             cout << j << " " << lastr << " " << R << "\n";
                cur += lastr - R;
            }
        }
        ans += cur;
    }
  //  cout << ans << "\n";
    ans %= MOD;
    ans = (-(ans + part % MOD) % MOD) * MOD1;
    ans %= MOD;
    cout << (MOD + ans % MOD) % MOD << "\n";
 //   -15800886 * x + y * 1755654 = unimodal
}