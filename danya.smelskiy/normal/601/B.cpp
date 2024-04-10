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
int a[100005];
int b[100005];

long long solve() {
    long long res = 0;
    stack<pair<long long, int> > s;
    long long sum = 0;
    for (int i = 2; i <= n; ++i) {
        s.push({abs(b[i] - b[i - 1]), 1});
        sum += s.top().first;
        while (s.size() > 1) {
            pair<long long, int> x = s.top();
            s.pop();
            pair<long long, int> y = s.top();
            if (y.first > x.first) {
                s.push(x);
                break;
            }
            sum -= y.first * y.second;
            sum += x.first * y.second;
            x.second += y.second;
            s.pop();
            s.push(x);
        }
        res += sum;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        n = 0;
        for (int i = l; i <= r; ++i)
            b[++n] = a[i];
        cout << solve() << '\n';
    }
}