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
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


LL powmod(LL x, LL y, LL m){
    LL a = 1;
    while(y){
        if( y & 1 ) a = a * x % m;
        y >>= 1;
        x = x * x % m;
    }
    return a;
}


int main(){
    int n, m;
    cin >> n >> m;

    LL ans = powmod(3, n, m) - 1;
    if( ans < 0 ) ans += m;
    cout << ans << endl;
}