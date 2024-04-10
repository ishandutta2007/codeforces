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

const int max_n = 1011, inf = 1111111111;

int n, p;
string s, k;

bool good(int poz) {
    if (poz == 0) {
        return true;
    }
    if (poz == 1) {
        return s[1] != s[0];
    }
    return s[poz] != s[poz - 1] && s[poz] != s[poz - 2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p >> s;
    k = s;
    int len = s.length();
    for (int i = len - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c < p + 'a'; ++c) {
            s[i] = c;
            if (good(i)) {
                int ff = 0;
                for (int j = i + 1; j < len; ++j) {
                    int f = 0;
                    for (char c2 = 'a'; c2 < p + 'a'; ++c2) {
                        s[j] = c2;
                        if (good(j)) {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0) {
                        s[j] = k[j];
                        ff = 1;
                        break;
                    }
                }
                if (ff == 0)  {
                    cout << s << endl;
                    return 0;
                }
            }
        }
        s[i] = k[i];
    }
    cout << "NO" << endl;
    return 0;
}