#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int Apply(vector<int>& values, int pos, int& t) {
    if (pos == (int) values.size() || t == 0) {
        return 0;
    }
    if (values[pos] <= 3) {
        int x = Apply(values, pos + 1, t);
        values[pos] += x;
        return 0;
    } else if (values[pos] >= 5) {
        values.resize(pos);
        --t;
        return 1;
    } else {
        int x = Apply(values, pos + 1, t);
        values[pos] += x;

        if (values[pos] == 5 && t > 0) {
            values.resize(pos);
            --t;
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<int> left;
    int pos = 0;
    {
        while (s[pos] != '.') {
            left.push_back(s[pos] - '0');
            ++pos;
        }
    }
    ++pos;
    vector<int> right;
    {
        while (pos < (int) s.length()) {
            right.push_back(s[pos] - '0');
            ++pos;
        }
    }

    int shift = Apply(right, 0, t);

    while (right.size() > 0 && right.back() == 0) {
        right.pop_back();
    }

    if (shift > 0) {
        reverse(left.begin(), left.end());
        ++left[0];
        int tmp = 0;
        for (int i = 0; i < (int) left.size(); ++i) {
            tmp += left[i];
            left[i] = tmp % 10;
            tmp /= 10;
        }
        while (tmp > 0) {
            left.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = (int) left.size() - 1; i >= 0; --i) {
            cout << left[i];
        }
        cout << endl;
    } else {
        for (int x : left) {
            cout << x;
        }
        if (right.size() > 0) {
            cout << ".";
            for (int x : right) {
                cout << x;
            }
        }
        cout << endl;
    }

    return 0;
}