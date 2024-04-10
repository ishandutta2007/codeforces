#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

string s;

long long str_to_int(string s) {
    long long x = 0;
    for (int i = 0; i < s.length(); ++i) {
        x = x * 10 + s[i] - '0';
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    if (s == "") {
        cout << "byte" << endl;
        return 0;
    }
    int z = 0;
    if (s[0] == '-') {
        z = -1;
        s.erase(0, 1);
    }
    if (s.length() < 19 || s.length() == 19 && s <= "9223372036854775807") {
        long long x = str_to_int(s), q = 1;
        for (int i = 0; i < 62; ++i) {
            q *= 2;
        }
        q = (q - 1) * 2 + 1;
        if (z == -1) {
            x = -x;
        }
        if (x >= -128 && x <= 127) {
            cout << "byte" << endl;
        } else {
            if (x >= -32768 && x <= 32767) {
                cout << "short";
            } else {
                if (x >= -2147483648LL && x <= 2147483647LL) {
                    cout << "int";
                } else {
                    if (x >= -q - 1 && x <= q) {
                        cout << "long";
                    }
                }
            }
        }
        return 0;
    }
    cout << "BigInteger" << endl;
    return 0;
}