#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


int main(){
    int x1, y1, z1, x, y, z, a[6];
    scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
    for(int i = 0; i < 6; ++i){
        scanf("%d", &a[i]);
    }

    int s = 0;
    if( y < 0  ) s += a[0];
    if( y > y1 ) s += a[1];
    if( z < 0  ) s += a[2];
    if( z > z1 ) s += a[3];
    if( x < 0  ) s += a[4];
    if( x > x1 ) s += a[5];
    
    printf("%d\n", s);
}