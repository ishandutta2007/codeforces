#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <cstdio>
#include <iostream>
using namespace std;

inline int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}
inline int read_int() {
#undef getchar_unlocked
#define getchar_unlocked read_char
    int sg = +1, ch;
    do {
        ch = getchar_unlocked();
        if (ch == '-') sg = -1;
    } while (ch < '0' || ch > '9');
    int x = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        x = x * 10 + ch - '0';
    }
    return sg * x;
}


void _R(int &x) { x=read_int(); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }


int N, M;
float a[100010];


int main() { 
    ios_base::sync_with_stdio(false);
    R(N, M);
    for (int i = 1; i <= N; ++i) a[i] = read_int();
    for (int j = 0; j < M; ++j) {
        int op, l, r;
        R(op, l, r);
        float x = read_int();
        if (op == 1) {
            for (int i = l; i <= r; ++i) if (a[i] > x) a[i] -= x;
        } else {
            int ans = 0;
            for (int i = l; i <= r; ++i) if (a[i] == x) ++ans;
            cout << ans << endl;
        }
    }
    return 0; 
}