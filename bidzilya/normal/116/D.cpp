#include <cstdio>
#include <cstring>

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

const int max_n = 150;

int n, m;
string s[max_n];

int main() { 
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int ans = 0, cpos = 0;
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0) {
            int l = cpos;
            for (int j = cpos + 1; j < m; ++j)
                if (s[i][j] == 'W')
                    l = j;
            if (i + 1 < n)
                for (int j = l + 1; j < m; ++j)
                    if (s[i + 1][j] == 'W')
                        l = j;
            ans += l - cpos;
            cpos = l;
        } else {
            int l = cpos;
            for (int j = cpos; j >= 0; --j)
                if (s[i][j] == 'W')
                    l = j;
            if (i + 1 < n)
                for (int j = l - 1; j >= 0; --j)
                    if (s[i + 1][j] == 'W')
                        l = j;
            ans += cpos - l;
            cpos = l;
        }
    ans += n - 1;
    for (int i = n - 1; i > 0; --i) {
        bool norm = 1;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'W') {
                norm = 0;
                break;
            }
        if (!norm) break;
        --ans;
    }
    cout << ans << endl;
    
    return 0;
}