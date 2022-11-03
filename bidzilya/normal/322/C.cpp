#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

int main() {
    ios_base::sync_with_stdio(false); 
    int a, b;
    string s;
    cin >> a >> b >> s;
    int x[110], y[110];
    x[0] = 0;
    y[0] = 0;
    for (int i = 0; i < s.length(); ++i) {
        x[i + 1] = x[i];
        y[i + 1] = y[i];
        if (s[i] == 'U') ++y[i + 1];
        if (s[i] == 'D') --y[i + 1];
        if (s[i] == 'R') ++x[i + 1];
        if (s[i] == 'L') --x[i + 1];
    }
    int xd = x[s.length()];
    int yd = y[s.length()];
    for (int i = 0; i <= s.length(); ++i) {
        int ta = a - x[i];
        int tb = b - y[i];
        if (xd == 0 && yd == 0 && ta == 0 && tb == 0 ||
            xd == 0 && yd != 0 && ta == 0 && tb % yd == 0 && tb / yd >= 0 ||
            xd != 0 && yd == 0 && ta % xd == 0 && ta / xd >= 0 && tb == 0 ||
            xd != 0 && yd != 0 && ta % xd == 0 && tb % yd == 0 &&
            ta / xd == tb / yd && ta / xd >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    return 0;
}