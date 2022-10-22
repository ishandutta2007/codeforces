#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1100;
const int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int a) {
    if (a % 4 != 0) return false;
    if (a % 100 == 0) {
        if (a % 400 == 0) return true;
        return false;
    } 
    return true;
}


int day(int a, int b, int c) {
    int ans = 0;
    for (int i = 1900; i <= a; ++i) {
        if (i < a) {
            if (check(i)) ans += 366; else ans += 365;
        } else {
            for (int j = 0; j < b - 1; ++j) {
                ans += M[j];
                if (j == 1 && check(i)) ++ans;
            }
            ans += c;
        }
    }
    
    return ans;
}


int main() {
    int a, b, c, d, e, f;
    a = b = c = d = e = f = 0;
    
    string p;
    cin >> p;
    for (int i = 0; i < 4; ++i) a = a * 10 + p[i] - '0';
    for (int i = 5; i < 7; ++i) b = b * 10 + p[i] - '0';
    for (int i = 8; i < 10; ++i) c = c * 10 + p[i] - '0';
    cin >> p;
    for (int i = 0; i < 4; ++i) d = d * 10 + p[i] - '0';
    for (int i = 5; i < 7; ++i) e = e * 10 + p[i] - '0';
    for (int i = 8; i < 10; ++i) f = f * 10 + p[i] - '0';
    
    
    if (a < d || (a == d && b < e) || (a == d && b == e && c < f)) {
        swap(a, d);
        swap(b, e);
        swap(c, f);
    }
    
    cout << day(a, b, c) -  day(d, e, f) << endl;
    
    return 0;
}