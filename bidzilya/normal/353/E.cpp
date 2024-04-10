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

const int max_n = 1e6 + 100;

string s;
int n;
int l[max_n], r[max_n];
int ans;

void try_ans(int v0) {
    int cans = 1;
    for (int i = v0 + 1, v = v0; (i % n) != (v0 % n); ++i) {
        int d = (i - v + 10 * n) % n;
        if (d <= r[v % n] || d <= l[i % n]) continue;
        d = (v0 - i + 10 * n) % n;
        if (d <= r[i % n] || d <= l[v0 % n]) continue;
        v = i;
        ++cans;
    }
    ans = max(ans, cans);
}

int main() {
    getline(cin, s);
    n = s.length();
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') {
            l[(i + 1) % n] = 0;
            for (int j = i + 2 + 10 * n; (j % n) != ((i + 1) % n); ++j) 
                if (s[(j - 1) % n] == '1')
                    l[j % n] = 0;
                else
                    l[j % n] = l[(j - 1) % n] + 1;
            break;
        }
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') {
            r[i % n] = 0;
            for (int j = i - 1 + 10 * n; (j % n) != (i % n); --j)
                if (s[j % n] == '0')
                    r[j % n] = 0;
                else
                    r[j % n] = r[(j + 1) % n] + 1;
            break;
        }

    ans = 1;
    try_ans(0);
    try_ans(1);
    
    cout << ans << endl;
    return 0;
}