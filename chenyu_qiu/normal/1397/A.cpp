#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cctype>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<ll> vecl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T>
inline void read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return ;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1:1;
    ret = (c == '-') ? 0:(c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return ;
}
inline void outi(int x) {if (x > 9) outi(x / 10);putchar(x % 10 + '0');}
inline void outl(ll x) {if (x > 9) outl(x / 10);putchar(x % 10 + '0');}
const int maxn = 1e3 + 10;
char s[maxn];
int cnt[256] = {0};
int main() {
    int t; read(t);
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int n; read(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            for (int j = 0; j < len; j++) cnt[s[j]]++;
        }
        bool flag = false;
        for (int i = 'a'; i <= 'z'; i++) if (cnt[i] % n != 0) flag = true;
        if (!flag) printf("YES\n");
        else printf("NO\n");
    }
}