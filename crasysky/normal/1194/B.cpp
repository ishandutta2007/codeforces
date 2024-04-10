#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 100005;
string s[maxn];
int c[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;;
}
int main(){
    int q = read();
    while (q --){
        int n = read(), m = read();
        for (int i = 0; i < n; ++ i)
            cin >> s[i];
        for (int i = 0; i < n; ++ i){
            c[i] = 0;
            for (int j = 0; j < m; ++ j)
                c[i] += s[i][j] == '*';
        }
        int ans = 0;
        for (int j = 0; j < m; ++ j){
            int cj = 0;
            for (int i = 0; i < n; ++ i)
                cj += s[i][j] == '*';
            for (int i = 0; i < n; ++ i)
                ans = max(ans, cj + c[i] - (s[i][j] == '*'));
        }
        cout << (n + m - 1) - ans << endl;
    }
}