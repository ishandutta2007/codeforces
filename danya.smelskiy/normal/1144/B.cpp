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


int n;
long long s;
vector<int> v1, v2;


inline long long solve(vector<int> v, vector<int> vv) {
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    reverse(v.begin(), v.end());
    reverse(vv.begin(), vv.end());
    int l = 0;
    int r = 0;
    long long sum = 0;
    for (int i = 1; ; ++i) {
        if (i & 1) {
            if (l == v.size()) return sum;
            sum += v[l++];
        } else {
            if (r == vv.size()) return sum;
            sum += vv[r++];
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x & 1) v1.push_back(x);
        else v2.push_back(x);
        s += x;
    }
    cout << s - max(solve(v1, v2), solve(v2, v1)) << '\n';
    
}