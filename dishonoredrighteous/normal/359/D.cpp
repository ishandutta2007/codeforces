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
const int N = 1 << 19;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int a[N];

class Node {
public:
    int val, min, g;

    Node() = default;

    Node(int _val, int _min, int _g) : val(_val), min(_min), g(_g) {}
};

class Stack {
public:
    std::vector<Node> st;

    void push(int val) {
        if (st.empty()) {
            st.push_back(Node(val, val, val));
        } else {
            st.push_back(Node(val, std::min(val, st.back().min), gcd(val, st.back().g)));
        }
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st.back().val;
    }

    bool empty() {
        return st.empty();
    }

    Node getNode() {
        return st.back();
    }
};

class Queue {
public:
    Stack head, tail;

    void push(int val) {
        tail.push(val);
    }

    void pop() {
        if (head.empty()) {
            while (!tail.empty()) {
                int val = tail.top();
                tail.pop();
                head.push(val);
            }
        }
        head.pop();
    }

    int getGcd() {
        int g = 0;
        if (!head.empty()) {
            g = gcd(g, head.getNode().g);
        }
        if (!tail.empty()) {
            g = gcd(g, tail.getNode().g);
        }
        return g;
    }

    int getMin() {
        int min = INF;
        if (!head.empty()) {
            min = std::min(min, head.getNode().min);
        }
        if (!tail.empty()) {
            min = std::min(min, tail.getNode().min);
        }
        return min;
    }
};

bool check(int n, int len) {
    Queue q;
    for (int i = 0; i < len - 1; ++i) {
        q.push(a[i]);
    }
    for (int i = len - 1; i < n; ++i) {
        q.push(a[i]);
        if (q.getMin() == q.getGcd()) {
            return true;
        }
        q.pop();
    }
    return false;
}

void printAns(int n, int len) {
    std::vector<int> ans;
    Queue q;
    for (int i = 0; i < len - 1; ++i) {
        q.push(a[i]);
    }
    for (int i = len - 1; i < n; ++i) {
        q.push(a[i]);
        if (q.getMin() == q.getGcd()) {
            ans.push_back(i - len + 1);
        }
        q.pop();
    }

    printf("%d %d\n", (int)ans.size(), len - 1);
    for (auto i : ans) {
        printf("%d ", i + 1);
    }
    printf("\n");
}

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        if (check(n, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    printAns(n, l);
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