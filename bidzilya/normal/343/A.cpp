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

ll a, b;
ll ans;

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> a >> b;
    ans = 0;
    while (a != b) {
        if (a < b) swap(a, b);
        ll k = (a - b) / b;
        if (k * b < a - b) ++k;
        ans += k;
        a -= k * b;
    }  
    ++ans;
    cout << ans << endl;
    return 0;
}