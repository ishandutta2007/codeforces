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

int len;
string n;

bool ok(string s) {
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '4') {
            ++a;
        } else if (s[i] == '7') {
            ++b;
        } else {
            return false;
        }
    }
    return a == b;
}

void proc(int poz, int x, int y) {
    while (x < len) {
        n[poz] = '4';
        ++poz;
        ++x;
    }
    while (y < len) {
        n[poz] = '7';
        ++poz;
        ++y;
    }
}

void get_next(int poz) {
    while (n[poz] == '7') {
        n[poz] = '4';
        --poz;
    }
    n[poz] = '7';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (ok(n)) {
        cout << n << endl;
        return 0;
    }
    if (n.length() % 2 == 0) {
        string a;
        len = n.length() / 2;
        for (int i = 0; i < len; ++i) {
            a += '7';
        }
        for (int i = 0; i < len; ++i) {
            a += '4';
        }
        if (n <= a) {
            int poz, x = 0, y = 0;
            for (int i = 0; i < n.length(); ++i) {
                if (n[i] != '4' && n[i] != '7') {
                    poz = i;
                    break;
                }
                if (n[i] == '4') {
                    ++x;
                } else {
                    ++y;
                }
                if (x > len) {
                    --x;
                    poz = i;
                    break;
                }
                if (y > len) {
                    --y;
                    poz = i;
                    break;
                }
            }
            if (x < len && n[poz] < '4') {
                proc(poz, x, y);
            } else if (y < len && n[poz] < '7') {
                ++y;
                n[poz] = '7';
                ++poz;
                proc(poz, x, y);
            } else {
                get_next(poz - 1);
                while (true) {
                    x = 0;
                    y = 0;
                    for (int i = 0; i < poz; ++i) {
                        if (n[i] == '4') {
                            ++x;
                        } else {
                            ++y;
                        }
                    }
                    if (x <= len && y <= len) {
                        break;
                    }
                    get_next(poz - 1);
                }
                proc(poz, x, y);
            }
            cout << n << endl;
        } else {
            for (int i = 0; i <= len; ++i) {
                cout << 4;
            }
            for (int i = 0; i <= len; ++i) {
                cout << 7;
            }
        }
    } else {
        int len = n.length() / 2 + 1;
        for (int i = 0; i < len; ++i) {
            cout << 4;
        }
        for (int i = 0; i < len; ++i) {
            cout << 7;
        }
        cout << endl;
    }
    return 0;
}