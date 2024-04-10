#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int M = 50005;
const int MOD = 998244353;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int n){
    int x, y;
    int g = gcd(n,MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, m;
int dist[M][N];
int ifact = 1, ans = 0;

int solve(int* d){
    int tmp = 1;
    for(int i = 1; i<=n; i++){
        if(d[i] < i) return 1;
        grow(tmp, d[i]-i+1);
    }
    return sub(1, mul(tmp, ifact));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++)  cin >> dist[j][i], --dist[j][i];
    for(int i = 1; i<=m; i++) sort(dist[i]+1, dist[i]+n+1);
    for(int i = 1; i<=n; i++) grow(ifact, i);
    ifact = inv(ifact);
    for(int t = 1; t<=m; t++) inc(ans, solve(dist[t]));
    cout << ans << endl;
}