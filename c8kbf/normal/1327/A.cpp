
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

_ x, y, tc;

int main() {
    
    scanf("%lld", &tc);
    for(; tc--; ) {
        scanf("%lld%lld", &x, &y);
        if(y*y > x || ((x-y*y)&1)) puts("NO");
        else puts("YES");
    }
    
    
    return 0;
}