#include <algorithm>
#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
const long long INF = 1LL << 60;
int a[102][102];
long long f[3000006];
string s;
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), m = read();
    cin >> s;
    for (int i = 1; i < n; ++ i){
        int x = s[i - 1] - 'a' + 1, y = s[i] - 'a' + 1;
        if (x != y)
            ++ a[x][y], ++ a[y][x];
    }
    for (int s = 1; s < 1 << m; ++ s){
        f[s] = INF;
        int c = 0;
        for (int i = 1; i <= m; ++ i)
            if (s & (1 << i - 1))
                ++ c;
        for (int i = 1; i <= m; ++ i)
            if (s & (1 << i - 1)){
                long long sum = 0;
                for (int j = 1; j <= m; ++ j)
                    if (s & (1 << j - 1))
                        sum += a[i][j] * c;
                for (int j = 1; j <= m; ++ j)
                    if ((s & (1 << j - 1)) == 0)
                        sum -= a[i][j] * c;
                f[s] = min(f[s], f[s ^ (1 << i - 1)] + sum);
            }
    }
    cout << f[(1 << m) - 1] << endl;
}