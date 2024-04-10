
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
typedef const long long constant;

_ x, y, z;

int main() {
    
    scanf("%lld%lld%lld", &x, &y, &z);
    if(!z) puts(x == y ? "YES" : "NO");
    else puts((y-x)%z || ((z > 0 && y < x) || (z < 0 && y > x)) ? "NO" : "YES");
    
    return 0;
}