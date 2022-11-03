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

string s;
int m;
vector<int> ans;

bool try_pick(int M) {
    for (int start = 1; start <= 10; ++start) {
        if (s[start - 1] == '0') continue;
        int d = start, p = start;
        ans.clear();
        ans.push_back(d);
        int m = M - 1;
        bool rans = 1;
        while (m) {
            bool fnd = 0;
            for (int i = 1; i <= 10; ++i)
                if (i > d && i != p && s[i - 1] == '1') {
                    p = i;
                    d = i - d;
                    ans.push_back(i);
                    fnd = 1;
                    --m;
                    break;
                }
            if (!fnd) {
                rans = 0;
                break;
            }
        }
        if (rans) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> s >> m;
    if (try_pick(m)) {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i)
            cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}