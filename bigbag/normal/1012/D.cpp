#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char tmp[max_n];
string a, b;
vector<int> l1, l2;

string read() {
    scanf("%s", tmp);
    return tmp;
}

int get_cnt(const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[0]) {
            return i;
        }
    }
    return s.length();
}

void op(int c1, int c2) {
    l1.push_back(c1);
    l2.push_back(c2);
    string ra = a.substr(0, c1);
    string rb = b.substr(0, c2);
    a = rb + a.substr(c1);
    b = ra + b.substr(c2);
}

deque<int> getv(const string &s) {
    deque<int> res;
    for (int i = 0; i < s.length(); ) {
        int pos = i;
        while (pos < s.length() && s[pos] == s[i]) {
            ++pos;
        }
        res.push_back(pos - i);
        i = pos;
    }
    return res;
}

int solve() {
    int s1 = 0, s2 = 0;
    deque<int> v1 = getv(a);
    deque<int> v2 = getv(b);
    bool f = true;
    int it = 0;
    while (true) {
        int c1 = v1.front();
        int c2 = v2.front();
        if (v1.size() == 1 && v2.size() == 1) {
            break;
        }
        if (f && a.length() && b.length() && a[0] == b[0]) {
            l1.push_back(c1);
            l2.push_back(0);
            v1.pop_front();
            s2 += c1;
        } else {
            l1.push_back(s1 + c1);
            l2.push_back(s2 + c2);
            v1.pop_front();
            v2.pop_front();
            if (v1.empty()) {
                v1.push_back(0);
            }
            if (v2.empty()) {
                v2.push_back(0);
            }
            swap(s1, s2);
            s1 += c2;
            s2 += c1;
        }
        f = false;
    }
    return l1.size();
}

int get_l(const string &s, int num) {
    if (num == 0) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < s.length(); ) {
        int pos = i;
        while (s[pos] == s[i]) {
            ++pos;
        }
        i = pos;
        ++res;
        if (res == num) {
            return pos;
        }
    }
}

void first_op(int c1, int c2) {
    op(get_l(a, c1), get_l(b, c2));
}

int sol(const string &s) {
    int res = 0;
    for (int i = 0; i < s.length(); ) {
        int pos = i;
        while (pos < s.length() && s[pos] == s[i]) {
            ++pos;
        }
        i = pos;
        ++res;
    }
    return res;
}

bool inv;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    a = read();
    b = read();
    int c1 = sol(a);
    int c2 = sol(b);
    if (c1 < c2) {
        swap(a, b);
        swap(c1, c2);
        inv = true;
    }
    if (a[0] == b[0]) {
        int len = 0;
        while (true) {
            if (len == 0) {
                len = 1;
                --c1;
            } else {
                len += 2;
                c1 -= 2;
                c2 += 2;
            }
            if (c1 <= c2 + 1) {
                break;
            }
        }
        int len2 = 0;
        if (c1 + 2 == c2) {
            --len;
            ++len2;
        }
        first_op(len, len2);
    } else if (c1 > c2 + 2) {
        int sum = (c1 + c2 - 2) / 2;
        if (c1 % 2 != c2 % 2) {
            if ((c1 - c2) % 4 == 1) {
                first_op(c1 - sum - 1, 1);
            } else {
                first_op(c1 - sum, 1);
            }
        } else {
            first_op(c1 - sum, 1);
        }
    }
    solve();
    printf("%d\n", l1.size());
    for (int i = 0; i < l1.size(); ++i) {
        if (inv) {
            swap(l1[i], l2[i]);
        }
        printf("%d %d\n", l1[i], l2[i]);
    }
    return 0;
}