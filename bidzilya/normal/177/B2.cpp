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

int n;
map<int, ll> mp;

ll go(int n) {
    if (mp.find(n) != mp.end())
        return mp[n];
    ll res = n;
    for (int i = 1; i <= sqrt(n); ++i)
        if (n % i == 0) {
            if (i > 1) 
                res = max(res, n + go(n / i));
            if (n > i) 
                res = max(res, n + go(i));
        }
    mp[n] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    cout << go(n) << endl;
    return 0;
}