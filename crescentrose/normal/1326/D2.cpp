#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using  namespace std;
const int M = 1e6 + 10;
const int SS = 18;
struct node {
    int son[26];
    int fail[SS + 1], len;
    void clear() {
        for (int i = 0; i < 26; i++)
            son[i] = 0;
        memset(fail, 0, sizeof(fail));
        len = 0;
    }
} tri[M];
char S[M];
int lst, L, N, len;
int loc[M];
void pre() {
    S[0] = -1;
    tri[1].clear();
    tri[0].clear();
    tri[1].len = -1;
    tri[0].fail[0] = 1;
    lst = 0;
    L = 1;
}
int getfail(int x) {
    while (S[N] != S[N - tri[x].len - 1])x = tri[x].fail[0];
    return x;
}

void add() {
    static int y;
    y = getfail(lst);
    if (!tri[y].son[S[N] - 'a']) {
        tri[++L].clear();
        tri[L].fail[0] = tri[getfail(tri[y].fail[0])].son[S[N] - 'a'], tri[L].len = tri[y].len + 2;
        tri[y].son[S[N] - 'a'] = L;
        if (tri[L].fail[0] > 1)
            for (int i = 0; tri[tri[L].fail[i]].fail[i] && i < SS; i ++)
                tri[L].fail[i + 1] = tri[tri[L].fail[i]].fail[i];
    }
    lst = tri[y].son[S[N] - 'a'];
}
int get(int l, int r) {
    if (l > r) return 0;
    int x = loc[r];
    l = r - l + 1;
    int i = SS;
    if (tri[x].len <= l) return tri[x].len;
    while (tri[tri[x].fail[0]].len > l) {
        if (!tri[x].fail[i] || tri[tri[x].fail[i]].len <= l) {
            i --;
        }else
            x = tri[x].fail[i];
    }
    return tri[tri[x].fail[0]].len;
}
pair<int, int> work(int n) {
    pre();
    for (N = 1; N <= n; N ++) {
        add();
        loc[N] = lst;
    }
    int ans = get(1, n);
    int l = 1;
    int ansl = 0, ansr = ans;
    while (S[l] == S[n - l + 1] && l < n - l + 1) {
        int v = get(l + 1, n - l);
        if (ans < v + l * 2) {
            ans = v + l * 2;
            ansl = l;
            ansr = v;
        }
        ++l;
    }
    return make_pair(ansl, ansr);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", S + 1);
        int len = strlen(S + 1);
        auto u = work(len);
        reverse(S+1, S + len + 1);
        auto v = work(len);
        if (u.first * 2 + u.second > v.first * 2 + v.second) {
            reverse(S+1, S + len + 1);
        } else {
            swap(u, v);
        }
        for (int i = 1; i <= u.first; i ++)
            printf("%c", S[i]);
        for (int i = len - (u.first + u.second) + 1; i <=len; i ++)
            printf("%c", S[i]);
        puts("");
    }
    return 0;
}