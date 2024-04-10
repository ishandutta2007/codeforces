#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<map<char, int>> T = {{}};
vector<int> cnt;

void Add(string str) {
    int node = 0;
    for (auto c : str) {
        int& nxt = T[node][c];
        if (nxt == 0) {
            nxt = T.size();
            T.emplace_back();
        }
        node = nxt;
    }
    cnt.resize(T.size(), 0);
    cnt[node] += 1;   
}

priority_queue<int> Solve(int node, int dep) {
    priority_queue<int> ret;
    for (int i = 0; i < cnt[node]; ++i)
        ret.push(dep);

    for (auto vec : T[node]) {
        auto have = Solve(vec.second, dep + 1);
        if (have.size() > ret.size()) swap(have, ret);
        while (have.size()) {
            ret.push(have.top());
            have.pop();
        }
    }
    if (node && cnt[node] == 0) {
        ret.pop();
        ret.push(dep);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        Add(str);
    }
    
    auto have = Solve(0, 0);
    int ret = 0;
    while (have.size()) {
        ret += have.top();
        have.pop();
    }
    cout << ret << endl;

    return 0;
}