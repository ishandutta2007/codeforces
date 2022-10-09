#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

struct stdio_interaction {
    int n, k;
    stdio_interaction() {
        cin >> n >> k;
    }
    
    bool ask(int a, int b, int c) {
        printf("? %d %d %d\n", a, b, c); fflush(stdout);
        string ans; cin >> ans;
        return tolower(ans[0]) != 'n';
    }

    void answer(int x) {
        printf("! %d", x);
    }
};

stdio_interaction io;

#define maxn 2000
int n, k;
int lv[maxn];

vector<int> get_between(int u, int v) {
    vector<int> res;
    rep1(i, n) 
        if (io.ask(u, i, v)) res.push_back(i);
    return res;
}

int get_subtreesize(int root, int u) {
    int ans = 0;
    rep1(i, n)
        ans += io.ask(root, u, i);
    return ans;
}

int main(void) {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    n = io.n; k = io.k;

    vector<int> cnt;
    for (int treesize = 0; treesize <= n; treesize = treesize * k + 1) cnt.push_back(treesize);
    reverse(cnt.begin(), cnt.end());
    rep(i, len(cnt)) lv[cnt[i]] = i;
    
    int treesize1 = get_subtreesize(2, 1);
    if (treesize1 > n - treesize1) treesize1 = (n - treesize1) * k + 1;
    if (treesize1 == n) {
        io.answer(1);
        return 0;
    }

    // clog << "lv 1 " << treesize1 << ' ' << lv[treesize1] << endl;

    vector<int> remain;
    rep1(i, n - 1) remain.push_back(i + 1);
    while (1) {
        int u = (int)(rand() % len(remain));
        swap(remain.back(), remain[u]);
        u = remain.back(); remain.pop_back();
        
        int treesize = get_subtreesize(1, u);
        if (treesize > n - treesize) continue;
        // clog << "clog " << u << ' ' << treesize << ' ' << lv[treesize] << endl;
        auto between = get_between(1, u);
        // clog << "between ";
        // for (auto i: between) clog << i << ' ' ;
        // clog << endl;
        if (len(between) - 1 != lv[treesize1] + lv[treesize]) continue;
        // clog << "picked" << endl;

        sort(between.begin(), between.end(), [](int x, int y) { return io.ask(1, x, y); });

        io.answer(between[lv[treesize1]]);
        break;
    }


    return 0;
}