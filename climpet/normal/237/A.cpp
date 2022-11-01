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


bool np[100005];

int main(){
    map<pii,int> mp;
    int n, h, m;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &h, &m);
        ans = max(ans, ++mp[pii(h, m)]);
    }

    printf("%d\n", ans);
}