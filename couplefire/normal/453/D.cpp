#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1<<20;
int MOD;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return (__int128)a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

void XOR(int* a, int n, int x){
    for(int i = 1; i<(1<<n); i<<=1)
        for(int j = 0; j<(1<<n); j+=(i<<1))
            for(int k = 0; k<i; ++k){
                int u = a[j+k], v = a[i+j+k];
                a[j+k] = add(u, v);
                a[j+k+i] = sub(u, v);
            }
    if(x<0)
        for(int i = 0; i<(1<<n); ++i)
            a[i] /= (1<<n);
}

int n, t;
int e[N], a[N], b[21];

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t >> MOD; MOD *= (1<<n);
    for(int i = 0; i<(1<<n); i++)
        cin >> e[i], e[i] %= MOD;
    for(int i = 0; i<=n; ++i)
        cin >> b[i], b[i] %= MOD;
    for(int i = 0; i<(1<<n); ++i)
        a[i] = b[__builtin_popcountll(i)];
    XOR(e, n, 1); XOR(a, n, 1);
    while(t){
        if(t&1)
            for(int i = 0; i<(1<<n); ++i)
                grow(e[i], a[i]);
        for(int i = 0; i<(1<<n); ++i)
            grow(a[i], a[i]);
        t >>= 1;
    }
    XOR(e, n, -1);
    for(int i = 0; i<(1<<n); ++i)
        cout << e[i] << '\n';
}