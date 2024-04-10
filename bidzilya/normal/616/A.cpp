#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Compare(const string& a, const string& b) {
    if (a.length() < b.length()) {
        return -1;
    }
    if (a.length() > b.length()) {
        return 1;
    }
    for (int i = 0; i < (int) a.length(); ++i) {
        if (a[i] > b[i]) {
            return 1;
        }
        if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

void DelLeadingZeros(string& s) {
    reverse(s.begin(), s.end());
    while (s.length() > 1 && s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
}

char GetSign(int d) {
    if (d < 0) {
        return '<';
    } else if (d == 0) {
        return '=';
    } else {
        return '>';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    DelLeadingZeros(a);
    DelLeadingZeros(b);

    cout << GetSign(Compare(a, b)) << endl;

    return 0;
}