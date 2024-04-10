#include <bits/stdc++.h>
using namespace std;
#define MAXN 2025
#define MOD 998244353

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, m;
int finans;
int comb[2*MAXN][2*MAXN];

int solve(){
    int ans = 0;
    for(int h = 1; h<=n-1; h++){
        int num[m]; num[0] = 1;
        for(int i = 1; i<m; i++) num[i] = sub(mul(comb[i+h][i], comb[i+n-h][i]), mul(comb[i-1+h][i-1], comb[i-1+n-h][i-1]));
        int p1[m], p2[m], p3[m];
        p1[0] = 1, p2[0] = 1, p3[0] = 1;
        for(int i = 1; i<m; i++) p1[i] = add(p1[i-1], comb[i+h-1][i]);
        for(int i = 1; i<m; i++) p2[i] = add(p2[i-1], comb[i+n-h-1][i]);
        for(int i = 1; i<m; i++) p3[i] = add(p3[i-1], num[i]);
        int s1 = 0, s2 = 0, s3 = 0;
        for(int i = 0; i<m; i++) inc(s1, mul(comb[i+h-1][i], p1[m-1-i]));
        for(int i = 0; i<m; i++) inc(s2, mul(comb[i+n-h-1][i], p2[m-1-i]));
        for(int i = 0; i<m; i++) inc(s3, mul(num[i], p3[m-1-i]));
        inc(ans, mul(s1, s2)); dec(ans, s3);
    }
    return ans;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i<2*MAXN; i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j<i; j++) comb[i][j] = add(comb[i-1][j-1], comb[i-1][j]);
    }
    cin >> n >> m;
    inc(finans, solve());
    swap(n, m);
    inc(finans, solve());
    for(int i = 1; i<=n-1; i++){
        for(int j = 1; j<=m-1; j++){
            dec(finans, mul(mul(comb[i+j-1][j], comb[i+m-j-1][i]), mul(comb[n-i+j-1][n-i], comb[n-i+m-j-1][m-j])));
            dec(finans, mul(mul(comb[i+j-1][i], comb[i+m-j-1][m-j]), mul(comb[n-i+j-1][j], comb[n-i+m-j-1][n-i])));
        }
    }
    cout << finans << endl;
}