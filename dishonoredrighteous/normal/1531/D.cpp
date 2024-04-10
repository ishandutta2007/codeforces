// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 1 << 17;

const std::string cmds[] = {
    "lock",
    "unlock",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "indigo",
    "violet"
};

int cmdToId(const std::string& cmd) {
    if (cmd == "lock") {
        return 0;
    } else if (cmd == "unlock") {
        return 1;
    } else if (cmd == "red") {
        return 2;
    } else if (cmd == "orange") {
        return 3;
    } else if (cmd == "yellow") {
        return 4;
    } else if (cmd == "green") {
        return 5;
    } else if (cmd == "blue") {
        return 6;
    } else if (cmd == "indigo") {
        return 7;
    } else if (cmd == "violet") {
        return 8;
    } else {
        throw;
    }
}

class Node {
public:
    bool isLocked[2];
    int lastColor[2];
    int l, r;

    Node() {
        memset(isLocked, false, sizeof(isLocked));
        memset(lastColor, -1, sizeof(lastColor));
        l = -1;
        r = -1;
    }

    Node(int curColor, int _l, int _r) {
        if (curColor == 0) {
            memset(isLocked, true, sizeof(isLocked));
            memset(lastColor, -1, sizeof(lastColor));
        } else if (curColor == 1) {
            memset(isLocked, false, sizeof(isLocked));
            memset(lastColor, -1, sizeof(lastColor));
        } else {
            isLocked[0] = false;
            isLocked[1] = true;

            lastColor[0] = curColor;
            lastColor[1] = -1;
        }

        l = _l;
        r = _r;
    }

    Node operator+(const Node& other) const {
        Node result;
        for (int startLock = 0; startLock < 2; ++startLock) {
            int midLock = isLocked[startLock];

            result.isLocked[startLock] = other.isLocked[midLock];
            if (other.lastColor[midLock] != -1) {
                result.lastColor[startLock] = other.lastColor[midLock];
            } else {
                result.lastColor[startLock] = lastColor[startLock];
            }
        }

        result.l = l;
        result.r = other.r;
        return result;
    }
};

int a[N];
Node tree[2 * N];

void build() {
    for (int i = 0; i < N; ++i) {
        tree[i + N] = Node(a[i], i, i + 1);
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void upd(int v, int pos, int newVal) {
    if (tree[v].l + 1 == tree[v].r) {
        tree[v] = Node(newVal, tree[v].l, tree[v].r);
        return;
    }

    if (pos < tree[v * 2].r) {
        upd(v * 2, pos, newVal);
    } else {
        upd(v * 2 + 1, pos, newVal);
    }

    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

void run() {
    fastIO;

    int n;
    std::cin >> n;

    a[0] = cmdToId("blue");
    for (int i = 1; i <= n; ++i) {
        std::string cmd;
        std::cin >> cmd;
        a[i] = cmdToId(cmd);
    }

    build();
    std::cout << cmds[tree[1].lastColor[0]] << std::endl;
    
    int q;
    std::cin >> q;
    while (q--) {
        int pos;
        std::string val;
        std::cin >> pos >> val;
        int id = cmdToId(val);
        upd(1, pos, id);
        std::cout << cmds[tree[1].lastColor[0]] << std::endl;
    }
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}