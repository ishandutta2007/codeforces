#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_C = 6;

int n;
int q;
vector<string> a;
vector<char> b;

int result;

string cur;

bool Check() {
    string buf = cur;
    reverse(buf.begin(), buf.end());
    while (buf.size() > 1) {
        bool found = false;
        for (int i = 0; i < q; ++i) {
            if (buf.back() == a[i][0] && buf[buf.size() - 2] == a[i][1]) {
                buf.pop_back();
                buf.back() = b[i];
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    if (buf[0] == 'a') {
        return true;
    } else {
        return false;
    }
}

void Rec(int pos) {
    if (pos == n) {
        if (Check()) {
            ++result;
        }
        return;
    }
    for (char c = 'a'; c < 'a' + MAX_C; ++c) {
        cur[pos] = c;
        Rec(pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(q);
    b.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i];
    }

    result = 0;
    cur.resize(n);
    Rec(0);

    cout << result << endl;

    return 0;
}