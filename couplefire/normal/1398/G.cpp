#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(a) ((int)(a).size())

const int LOGN = 20;
const int N = (1 << LOGN);
const int K = 200043;
const int M = 1000043;

typedef double ld;
typedef long long li;

const ld PI = acos(-1.0);

struct comp 
{
    ld x, y;
    comp(ld x = .0, ld y = .0) : x(x), y(y) {}
    inline comp conj() { return comp(x, -y); }
};

inline comp operator +(const comp &a, const comp &b) 
{
    return comp(a.x + b.x, a.y + b.y);
}

inline comp operator -(const comp &a, const comp &b) 
{
    return comp(a.x - b.x, a.y - b.y);
}

inline comp operator *(const comp &a, const comp &b) 
{
    return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

inline comp operator /(const comp &a, const ld &b) 
{
    return comp(a.x / b, a.y / b);
}

vector<comp> w[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
    for(int st = 0; st < LOGN; st++) 
    {
        w[st].assign(1 << st, comp());
        for(int k = 0; k < (1 << st); k++) 
        {
            double ang = PI / (1 << st) * k;
            w[st][k] = comp(cos(ang), sin(ang));
        }
        
        rv[st].assign(1 << st, 0);
        if(st == 0) 
        {
            rv[st][0] = 0;
            continue;
        }
        int h = (1 << (st - 1));
        for(int k = 0; k < (1 << st); k++)
            rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
}

inline void fft(comp a[N], int n, int ln, bool inv) 
{
    for(int i = 0; i < n; i++) 
    {
        int ni = rv[ln][i];
        if(i < ni)
            swap(a[i], a[ni]);
    }
    
    for(int st = 0; (1 << st) < n; st++) 
    {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) 
        {
            for(int pos = k; pos < k + len; pos++) 
            {
                comp l = a[pos];
                comp r = a[pos + len] * (inv ? w[st][pos - k].conj() : w[st][pos - k]);
                
                a[pos] = l + r;
                a[pos + len] = l - r;
            }
        }
    }
    
    if(inv) for(int i = 0; i < n; i++)
        a[i] = a[i] / n;
}

comp aa[N];
comp bb[N];
comp cc[N];

inline void multiply(comp a[N], int sza, comp b[N], int szb, comp c[N], int &szc) 
{
    int n = 1, ln = 0;
    while(n < (sza + szb))
        n <<= 1, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < sza ? a[i] : comp());
    for(int i = 0; i < n; i++)
        bb[i] = (i < szb ? b[i] : comp());
        
    fft(aa, n, ln, false);
    fft(bb, n, ln, false);
    
    for(int i = 0; i < n; i++)
        cc[i] = aa[i] * bb[i];
        
    fft(cc, n, ln, true);
    
    szc = n;
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
}

comp a[N];
comp b[N];
comp c[N];
int used[M];
int dp[M];

int main()
{
    precalc();
    int n, x, y;
    for(int i = 0; i < M; i++)
        dp[i] = -1;
    scanf("%d %d %d", &n, &x, &y);
    vector<int> A(n + 1);
    for(int i = 0; i <= n; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i <= n; i++)
    {
        a[A[i]] = comp(1.0, 0.0);
        b[K - A[i]] = comp(1.0, 0.0);
    }
    int s = 0;
    multiply(a, K + 1, b, K + 1, c, s);
    for(int i = K + 1; i < s; i++)
        if(c[i].x > 0.5)
            used[(i - K + y) * 2] = 1;
    for(int i = 1; i < M; i++)
    {
        if(!used[i]) continue;
        for(int j = i; j < M; j += i)
            dp[j] = max(dp[j], i);
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int l;
        scanf("%d", &l);
        printf("%d ", dp[l]);
    }
}