#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

string have;
vector<int> ops;
int n;

void Operate(int pos) {
    ops.push_back(pos);
    string stk;
    for (int i = 0; i < pos; ++i) {
        stk += have.back();
        have.pop_back();
    }
    have = stk + have;
}

void Match(string b) {
    if (b.empty()) return;

    char c = b.back();
    b.pop_back();
    reverse(b.begin(), b.end());
    Match(b);

    int pos_t = b.size(), pos_s = -1;
    for (int i = pos_t; i < (int)have.size(); ++i) {
        if (have[i] == c) {
            pos_s = i;
            break;
        }
    }
    assert(pos_s != -1);
    
    reverse(b.begin(), b.end());
    Operate(n - pos_s - 1);
    Operate(pos_s - pos_t + 1);
    Operate(pos_t);
//    cerr << "Match " << b + c << " -> " << have << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    string b; cin >> have >> b;

    string sa(have), sb(b);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    if (sa != sb) {
        cout << -1 << endl;
        return 0;
    }

    Match(b);
    assert(have == b);
    cout << ops.size() << endl;
    for (auto x : ops) cout << x << " ";
    cout << endl;

    return 0;
}