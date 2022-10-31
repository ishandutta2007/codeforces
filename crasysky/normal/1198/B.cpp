#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
#define maxn 200005
using namespace std;
pair <int, int> b[maxn];
int mx[maxn];
int read(){
    int cnt = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9'){
        cnt = cnt * 10 + ch - '0';
        ch = getchar();
    }
    return cnt;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        b[i] = mp(0, read());
    int q = read();
    for (int i = 1; i <= q; ++ i){
        int type = read();
        if (type == 1){
            int x = read();
            b[x] = mp(i, read());
        }
        else
            mx[i] = read();
    }
    for (int i = q; i; -- i)
        mx[i] = max(mx[i], mx[i + 1]);
    for (int i = 1; i <= n; ++ i)
        printf("%d ", max(b[i].se, mx[b[i].fi + 1]));
}