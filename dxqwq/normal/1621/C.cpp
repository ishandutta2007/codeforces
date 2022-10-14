#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
#define Flush fwrite(o_str,1,o_t,stdout), o_t = 0
#define space pc(' ')
#define enter pc('\n')

inline char gc() {
    if (i_s == i_t) {
        i_s = i_str;
        i_t = i_s + fread(i_str, 1, MAXL, stdin);
        return i_s == i_t ? EOF : *i_s++;
    } else
        return *i_s++;
}

inline int read() {
    int x = 0, f = 0;
    char ch = gc();
    for (; ch < '0' || ch > '9'; ch = gc())
        if (ch == '-')
            f = 1;
    for (; ch >= '0' && ch <= '9'; ch = gc())
        x = x * 10 + (ch ^ 48);
    return f ? -x : x;
}

inline void pc(char x) {
    o_str[o_t++] = x;
    if (o_t == MAXL)
        Flush;
}

void write(int x) {
    if (x < 0)
        pc('-'), x = -x;
    if (x > 9)
        write(x / 10);
    pc(x % 10 ^ 48);
}

const int N = 2e5 + 5; 

int nbr[N];

bool vis[N];

inline int Puh(int x) {
    cout << "? " << x << endl;
    int t;
    cin >> t;
    return t;
}

inline void Solve() {
	int n;
    cin >> n;
    for (register int i = 1; i <= n; ++i)
        nbr[i] = vis[i] = 0;
    for (register int i = 1; i <= n; ++i) {
        if (vis[i])
            continue ;
        int x = Puh(i), y = Puh(i);
        vis[x] = vis[y] = true;
        if (x == y) {
            nbr[x] = y;
            continue ;
        }
        vector <int> vct;
        vct.push_back(y);
        y = Puh(i), vis[y] = true;
        while (y != x)
            vct.push_back(y), y = Puh(i), vis[y] = true;
        vct.push_back(x);
        for (register int i = 1; i < vct.size(); ++i)
            nbr[vct[i - 1]] = vct[i];
        nbr[vct.back()] = vct[0];
    }
    cout << "! ";
    for (register int i = 1; i <= n; ++i)
        cout << nbr[i] << " ";
    cout << endl;
    return ;
}

signed main() {
    int T;
    cin >> T;
    while (T--)
        Solve();
    Flush ; 
    return 0;
}