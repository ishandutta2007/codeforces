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


#define MOD 1000000009LL


int main(){
    int a = INT_MAX, b = -1;
    int n;
    scanf("%d", &n);
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &l[i], &r[i]);
        a = min(a, l[i]);
        b = max(b, r[i]);
    }

    for(int i = 0; i < n; ++i){
        if( l[i] == a && r[i] == b ){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    puts("-1");
}