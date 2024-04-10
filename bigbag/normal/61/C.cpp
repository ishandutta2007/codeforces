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

const int inf = 111111111;

long long a, b, c;
string s, cc;

int str_to_int(string s) {
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        x = x * 10 + s[i] - '0';
    }
    return x;
}

string int_to_str(int x) {
    if (x == 0) {
        return "0";
    }
    string ret = "";
    while (x != 0) {
        ret += x % 10 + '0';
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string norm(string s) {
    int poz = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '0') {
            poz = i;
            break;
        }
    }
    return s.substr(poz, s.length() - poz);
}

long long proc1(string s, int k) {
    long long powers[100];
    powers[0] = 1;
    for (int i = 1; i < 100; ++i) {
        powers[i] = powers[i - 1] * k;
    }
    long long res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            res += powers[s.length() - i - 1] * (s[i] - '0');
        } else {
            res += powers[s.length() - i - 1] * (s[i] - 'A' + 10);
        }
    }
    return res;
}

string proc2(long long x, int k) {
    if (x == 0) {
        return "0";
    }
    string res = "";
    while (x != 0) {
        int a = x % k;
        x /= k;
        if (a < 10) {
            res += int_to_str(a);
        } else {
            res += 'A' + a - 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> s >> cc;
    cc = norm(cc);
    if (s == "R") {
        long long t = proc1(cc, a);
        while (t >= 1000) {
            cout << "M";
            t -= 1000;
        }
        if (t >= 900) {
            cout << "CM";
            t -= 900;
        }
        while (t >= 500) {
            cout << "D";
            t -= 500;
        }
        if (t >= 400) {
            cout << "CD";
            t -= 400;
        }
        while (t >= 100) {
            cout << "C";
            t -= 100;
        }
        if (t >= 90) {
            cout << "XC";
            t -= 90;
        }
        while (t >= 50) {
            cout << "L";
            t -= 50;
        }
        if (t >= 40) {
            cout << "XL";
            t -= 40;
        }
        while (t >= 10) {
            cout << "X";
            t -= 10;
        }
        if (t >= 9) {
            cout << "IX";
            t -= 9;
        }
        while (t >= 5) {
            cout << "V";
            t -= 5;
        }
        if (t >= 4) {
            cout << "IV";
            t -= 4;
        }
        while (t >= 1) {
            cout << "I";
            t -= 1;
        }
    } else {
        b = str_to_int(s);
        long long t = proc1(cc, a);
        cout << proc2(t, b) << endl;
    }
    return 0;
}