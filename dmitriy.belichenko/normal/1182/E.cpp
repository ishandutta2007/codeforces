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
typedef long long ll;
#define SZ 233333
int MOD=500000003; //or any prime
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
        for(int i=0;i<int(x.size());++i)
        {
            ll t=0;
            //evaluate at position i
            for(int j=0;j<int(cur.size());++j)
                t=(t+x[i-j-1]*(ll)cur[j])%MOD;
            if((t-x[i])%MOD==0) continue; //good so far
            //first non-zero position
            if(!cur.size())
            {
                cur.resize(i+1);
                lf=i; ld=(t-x[i])%MOD;
                continue;
            }
            ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
            vector<int> c(i-lf-1); //add zeroes in front
            c.pb(k);
            for(int j=0;j<int(ls.size());++j)
                c.pb(-ls[j]*k%MOD);
            if(c.size()<cur.size()) c.resize(cur.size());
            for(int j=0;j<int(cur.size());++j)
                c[j]=(c[j]+cur[j])%MOD;
            //if cur is better than ls, change ls to cur
            if(i-lf+(int)ls.size()>=(int)cur.size())
                ls=cur,lf=i,ld=(t-x[i])%MOD;
            cur=c;
        }
        for(int i=0;i<int(cur.size());++i)
            cur[i]=(cur[i]%MOD+MOD)%MOD;
        return cur;
    }
    int m;
    ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
    
    inline void mull(ll*p,ll*q)
    {
        for(int i=0;i<m+m;++i) t_[i]=0;
        for(int i=0;i<m;++i) if(p[i])
            for(int j=0;j<m;++j)
                t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
        for(int i=m+m-1;i>=m;--i) if(t_[i])
            for(int j=m-1;~j;--j)
                t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
        for(int i=0;i<m;++i) p[i]=t_[i];
    }
    inline ll calc(ll K)
    {
        for(int i=m;~i;--i)
            s[i]=t[i]=0;
        s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
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
        if(n< int(x.size()))
        {
            return x[n];
        }
        vector<int> v = BM(x);
        m = v.size();
        if(!m)
        {
            return 0;
        }
        for(int i = 0; i < m;++i)
        {
            h[i]=v[i];
            a[i]=x[i];
        }
        return calc(n);
    }
}
using linear_seq::work;
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int findMinX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    
    return result % prod;
}

signed main()
{
    int n, a , b , c , d;
    cin >> n >> a >> b >> c >> d;
    vector<int> st = {1, 3, 7, 15, 30, 58, 110, 206, 383, 709, 1309, 2413, 4444, 8180};
    vector<int> f1 = {1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927};
    vector<int> f2 = {1, 2, 3, 6, 11, 20, 37, 68, 125, 230, 423, 778, 1431};
    vector<int> f3 = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136};
    n-=4;
    ll cst = work(st, n);
    ll ca = work(f1, n);
    ll cb = work(f2, n);
    ll cc = work(f3, n);
    MOD = 2;
    ll oca = work(f1, n), ocb = work(f2, n) , occ = work(f3, n);
    int num[] = {2 , 500000003};
    int r1[] = {oca , ca};
    int r2[] = {ocb , cb};
    int r3[] = {occ , cc};
    int r4[] = {work(st, n),cst};
    ca = findMinX(num, r1, 2);
    cb = findMinX(num, r2, 2);
    cc = findMinX(num, r3, 2);
    cst = (2 *  findMinX(num, r4, 2)) % (500000003 * 2);
    MOD = 1e9 + 7;
    ll ans = qp(d , cst);
    ans *= qp(a , ca);
    ans %= (MOD);
    ans *= qp(b , cb);
    ans %= MOD;
    ans *= qp(c , cc);
    ans %= (MOD);
    cout << ans << "\n";
    
}//