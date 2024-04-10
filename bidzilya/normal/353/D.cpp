#include <cstdio>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

string s;
int n, m;

int main() {
    getline(cin, s);
    n = s.length();
    m = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'M') ++m;
    int ans = 0, c = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'M') {
            int cans = n - i - m + c;
            if (cans) cans += c;
            ans = max(ans, cans);
            ++c;
        }
    cout << ans << endl;
    return 0;
}