#include <bits/stdc++.h>
using namespace std;

#define clog if (0) cerr

const int max_alpha = 62;
const int max_node = max_alpha * max_alpha;

int encode_char(char ch) {
    if (isdigit(ch)) return ch - '0';
    if (islower(ch)) return 10 + ch - 'a';
    return 10 + 26 + ch - 'A';
}

char decode_char(int num) {
    if (num < 10) return char('0' + num);
    num -= 10;
    if (num < 26) return char('a' + num);
    num -= 26;
    return char('A' + num);
}

int encode(const string& s) {
    return encode_char(s[0]) * max_alpha + encode_char(s[1]);
}

string decode(int num) {
    return {decode_char(num / max_alpha), decode_char(num % max_alpha)};
}

int n;

vector<int> gr[max_node];
int in_deg[max_node];

list<int> euler_walk(int u) {
    if (gr[u].empty()) {
        return {u};
    }
    list<int> ans = {u};
    while (gr[u].size()) {
        int v = gr[u].back();
        gr[u].pop_back();
        ans.push_back(v);
        u = v;
    }
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        auto sub = euler_walk(*it);
        sub.pop_back();
        ans.splice(it, sub);
    }
    for (auto it: ans) clog << decode(it) << ' ';
    clog << endl;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int u = encode(s.substr(0, 2));
        int v = encode(s.substr(1, 2));
        gr[u].push_back(v);
        clog << s << ' ' << u <<' ' << v << ' ' << decode(u) <<' ' << decode(v) << endl;
        ++in_deg[v];
    }
    
    int start = -1;
    for (int i = 0; i < max_node; ++i) {
        if ((int)gr[i].size() == in_deg[i] + 1) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        for (int i = 0; i < max_node; ++i) {
            if ((int)gr[i].size()) {
                start = i;
                break;
            }
        }
    }
    if (start == -1) {
        start = 0;
    }
    clog << start << ' ' << decode(start) << endl;
    auto ans = euler_walk(start);
    if ((int)ans.size() != n + 1) {
        cout << "NO";
        return 0;
    }
    for (auto u = ans.begin(), v = next(ans.begin()); v != ans.end(); u = v++) {
        if (decode(*u)[1] != decode(*v)[0]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << decode(ans.front());
    ans.pop_front();
    for (auto it: ans) {
        cout << decode(it)[1];
    }
    
    return 0;
}