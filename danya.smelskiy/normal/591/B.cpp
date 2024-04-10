# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n, m;
int nxt[100];



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < 26; ++i)
        nxt[i] = i;
    while (m--) {
        char c1, c2;
        cin >> c1 >> c2;
        int x = c1 - 'a';
        int y = c2 - 'a';
        for (int i = 0; i < 26; ++i)
            if (nxt[i] == x) nxt[i] = y;
            else if (nxt[i] == y) nxt[i] = x;
    }
    for (int i = 0; i < n; ++i)
        cout << char('a' + nxt[s[i] - 'a']);
    cout << '\n';
}