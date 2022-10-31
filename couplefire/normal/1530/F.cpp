#include <bits/stdc++.h>
using namespace std;

const int N = 21, MOD = 31607;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int msb(int x){return 31-__builtin_clz(x);}

int n;
int grid[N][N], igrid[N][N];
int row_prod[N], col_mask[N][1<<N];
int ans;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> grid[i][j], grow(grid[i][j], inv(10000)),
            igrid[i][j] = inv(grid[i][j]);
    for(int i = 0; i<n; i++){
        row_prod[i] = 1;
        for(int j = 0; j<n; j++)
            grow(row_prod[i], grid[i][j]);
    }
    for(int j = 0; j<n; j++){
        col_mask[j][0] = 1;
        for(int i = 0; i<n; i++)
            grow(col_mask[j][0], grid[i][j]);
        for(int mask = 1, end = (1<<n); mask<end; ++mask)
            col_mask[j][mask] = mul(col_mask[j][mask^(1<<msb(mask))], igrid[msb(mask)][j]);
    }
    for(int mask = 0, end = (1<<(n+2)); mask<end; ++mask){
        int res = (__builtin_popcount(mask)%2?MOD-1:1);
        for(int i = 0; i<n; i++)
            if(mask&(1<<i)) grow(res, row_prod[i]);
        bool f1 = (mask&(1<<n)), f2 = (mask&(1<<(n+1)));
        if(f1)
            for(int i = 0; i<n; i++)
                if(!(mask&(1<<i))) grow(res, grid[i][i]);
        if(f2)
            for(int i = 0; i<n; i++)
                if(!(mask&(1<<i))) grow(res, grid[i][n-1-i]);
        if(f1 && f2 && n%2 && !(mask&(1<<(n/2))))
            grow(res, igrid[n/2][n/2]);
        int nmask = mask;
        if(f1) nmask ^= (1<<n);
        if(f2) nmask ^= (1<<(n+1));
        for(int j = 0; j<n; j++){
            int tmp = col_mask[j][nmask];
            if(f1 && !(nmask&(1<<j)))
                grow(tmp, igrid[j][j]);
            if(f2 && !(nmask&(1<<(n-1-j))))
                grow(tmp, igrid[n-1-j][j]);
            if(n%2 && j==n/2 && f1 && f2 && !(nmask&(1<<(n/2))))
                grow(tmp, grid[j][j]);
            grow(res, sub(1, tmp));
        }
        inc(ans, res);
    }
    cout << sub(1, ans) << '\n';
}