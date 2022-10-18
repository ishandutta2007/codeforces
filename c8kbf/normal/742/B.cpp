
#include <cstdlib>
 
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
 
#include <cmath>
#include <cstring>
#include <ctime>
 
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
 
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;

_ b[maxn], n, m, x, s;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        s += b[x];
        ++b[x^m];
    }
    printf("%lld\n", s);
    
    return 0;
}