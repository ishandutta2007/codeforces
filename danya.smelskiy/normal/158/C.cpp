# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n, all;


struct Node {
    string name;
    int pred;
    map<string, int> next;
    Node() {}
    Node(string _s, int p) {
        this -> name = _s;
        this -> pred = p;
    }
    
} w[100005];


int add_ivent(int x, string s) {
    if (s == "..") return w[x].pred;
    if (!w[x].next.count(s)) {
        w[x].next[s] = ++all;
        w[all] = Node(s, x);
    }
    return w[x].next[s];
}

void prnt_path(int x) {
    if (x == 1) {
        cout << "/\n";
        return;
    }
    vector<string> iv;
    while (x > 1) {
        iv.push_back("/" + w[x].name);
        x = w[x].pred;
    }
    string res = "";
    for (int i = (int)iv.size() - 1; i >= 0; --i)
        res += iv[i];
    res += "/";
    cout << res << '\n';
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    all = 1;
    w[all] = Node("", 0);
    int t;
    cin >> t;
    int cur = 1;
    while (t--) {
        string q;
        cin >> q;
        if (q[0] == 'p') {
            prnt_path(cur);
            continue;
        }
        cin >> q;
        if (q[0] == '/') {
            cur = 1;
            q.erase(q.begin());
        }
        q += "/";
        string last = "";
        for (int i = 0; i < q.size(); ++i) {
            if (q[i] == '/') {
                if ((int)last.size() > 0) {
                    cur = add_ivent(cur, last);
                    last = "";
                }
            } else last += q[i];
        }
    }
    return 0;
}