#include<bits/stdc++.h>
using namespace std;

int dir(char ch) { return ch == '+' ? 1 : -1; }
long double follow(int pos, int expected_pos, string::iterator beg, string::iterator end) {
    if (beg == end) return pos == expected_pos;
    if (*beg != '?') return follow(pos + dir(*beg), expected_pos, next(beg), end);
    return 0.5 * (follow(pos + 1, expected_pos, next(beg), end) + follow(pos - 1, expected_pos, next(beg), end));
}

int main() {
    string expected, received;
    cin >> expected >> received;
    int expected_pos = 0;
    for (auto i: expected) expected_pos += dir(i);
    cout << fixed << setprecision(10) << follow(0, expected_pos, received.begin(), received.end());
    return 0;
}