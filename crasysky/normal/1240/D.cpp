#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
const int base1 = 10007, base2 = 10009;
const int mod1 = 1000000009, mod2 = 1000000007;
int s[maxn], st[maxn];
int tp;
long long valx[maxn], valy[maxn];
pair <long long, long long> a[maxn];
void ins(int s){
	st[++ tp] = s;
	valx[tp] = (valx[tp - 1] * base1 + s) % mod1;
	valy[tp] = (valy[tp - 1] * base2 + s) % mod2;
}
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int T = read();
    while (T --){
        int n = read();
        for (int i = 1; i <= n; ++ i)
            s[i] = read();
        tp = 0;
        for (int i = 1; i <= n; ++ i){
            if (tp && s[i] == st[tp])
                -- tp;
            else
                ins(s[i]);
            a[i] = make_pair(valx[tp], valy[tp]);
        }
        sort(a, a + n + 1);
        int cnt = 0;
        long long ans = 0;
        for (int i = 0; i <= n; ++ i)
            if (i == 0 || a[i] != a[i - 1])
                cnt = 1;
            else
                ans += cnt ++;
        cout << ans << endl;
    }
}