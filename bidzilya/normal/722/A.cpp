#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>
using namespace std;

string GetString(int x) {
    if (x < 10) {
        return "0" + to_string(x);
    } else {
        return to_string(x);
    }
}

int GetDiff(const string& s1, const string& s2) {
    int r = 0;
    for (int i = 0; i < (int) s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            ++r;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string t;
    cin >> t;

    int curDiff = -1;
    string result;

    int h1, h2;
    if (n == 12) {
        h1 = 1;
        h2 = 12;
    } else if (n == 24) {
        h1 = 0;
        h2 = 23;
    } else {
        assert(false);
    }

    for (int nh = h1; nh <= h2; ++nh) {
        for (int nm = 0; nm < 60; ++nm) {
            string ct = GetString(nh) + ":" + GetString(nm);

            int diff = GetDiff(ct, t);

            if (curDiff == -1 || diff < curDiff) {
                curDiff = diff;
                result = ct;
            }
        }
    }

    cout << result << endl;

    return 0;
}