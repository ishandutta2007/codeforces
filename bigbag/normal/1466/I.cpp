/**
 *  created: 15/01/2021, 21:46:10
**/

#include <bits/stdc++.h>

using namespace std;

int n, b;

bool is_greater(int pos, const string &s) {
    cout << pos + 1 << " " << s << endl;
    string res;
    cin >> res;
    return res == "yes";
}

deque<int> q;

string fill_ones(string s) {
    if (s.size() > b) {
        s = s.substr(0, b);
    }
    while (s.size() < b) {
        s += '1';
    }
    return s;
}

int pos;
string ans;

void proc(int i) {
    while (!q.empty() && is_greater(i, fill_ones(ans))) {
        q.pop_back();
        assert(!ans.empty());
        ans.pop_back();
    }
    if (ans.size() == b) {
        return;
    }
    char c = '0' + is_greater(i, fill_ones(ans + "0"));
    ans += c;
    q.push_back(i);
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        proc(i);
    }
    while (!q.empty()) {
        int id = q.front();
        q.pop_front();
        proc(id);
    }
    cout << "0 " << ans << endl;
    return 0;
}