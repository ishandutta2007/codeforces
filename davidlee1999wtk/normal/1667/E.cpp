#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define P 998244353
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

LL ksm(LL a,LL b,LL mod)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%mod;
        d=(d*d)%mod;
        b>>=1;
    }
    return c;
}

LL inv(LL a)
{
    return ksm(a, P-2, P);
}

int yg = 3;

void brc(LL *y, int n)
{
    int i, j, k;
    for (i = 1, j = n / 2; i<n - 1; i++)
    {
        if (i<j)
            swap(y[i], y[j]);
        k = n / 2;
        while (j >= k)
            j -= k, k >>= 1;
        j += k;
    }
}

void fft(LL *y, int n, int op)
{
    int i, j, k, w, wn, u, t;
    brc(y, n);
    for (i = 2; i <= n; i <<= 1)
    {
        if (op == 1)
            wn = ksm(yg, (P - 1) / i, P);
        else
            wn = ksm(yg, (P - 1) - (P - 1) / i, P);
        for (j = 0; j<n; j += i)
        {
            w = 1;
            for (k = j; k<j + i / 2; k++)
            {
                u = y[k], t = y[k + i / 2] * w%P;
                y[k] = (u + t) % P;
                y[k + i / 2] = (u - t + P) % P;
                w = (LL)wn*w%P;
            }
        }
    }
    if (op == -1)
        for (i = 0; i<n; i++)
            y[i] = y[i] * ksm(n, P - 2, P) % P;
}

LL ans[N], fac[N], ifac[N], s1[N], s2[N];
LL f[N*4], g[N*4], h[N*4];

LL A(int n, int m)
{
    return fac[n] * ifac[n-m] % P;
}

int main()
{
    int n, k = 1, m, i, j;
    cin >> n;
    m = n/2;
    while(k < n)
        k <<= 1;
    fac[0] = ifac[0] = 1;
    for(i=1;i<=n;i++)
    {
        fac[i] = fac[i-1] * i % P;
        ifac[i] = inv(fac[i]);
    }

    for(i=1;i<=m+1;i++)
        ans[i] = fac[n-1]; // subtract invalid solution from all posibile solution

    // Case1: This subtree with root i is too small
    for(i=0, j = m;j<=n-2;i++, j++)
        f[i] = fac[j];
    for(i=0; i<n;i++)
        g[i] = ifac[n-i];
    fft(f, k, 1);
    fft(g, k, 1);
    for(i=0;i<k;i++)
        h[i] = f[i] * g[i] % P;
    fft(h, k, -1);
    for(i=1; i<=m+1; i++)
    {
        s1[i] = h[m+i-1] * (i-1) % P * fac[n] % P * inv(A(n,i)) % P;
        ans[i] = (ans[i] - s1[i] + P) % P;
    }

    // Case2: One of subtree of i is too large

    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for(i=0;i<m;i++)
        f[i] = ifac[i];
    for(i=0, j = m+1; j<=n-1;i++, j++)
    {
        g[i] = inv(j) * fac[n-j-1] % P;
    }
    fft(f, k, 1);
    fft(g, k, 1);
    for(i=0;i<k;i++)
        h[i] = f[i] * g[i] % P;
    
    fft(h, k, -1);

    //for(i=0;i<k;i++)
        //debug(h[i]);

    for(i=1; i<=m; i++)
    {
        s2[i] = h[m-i] % P * fac[n] % P * inv(A(n,i)) % P;
        //debug(s2[i]);
        ans[i] = (ans[i] - s2[i] + P) % P;
    }


    for(i=1;i<=n;i++)
        printf("%I64d ", ans[i]);
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);