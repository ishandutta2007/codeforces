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
#define EPS 1e-8


int main(){
    int m, n;
    scanf("%d", &m);
    int minq = INT_MAX, q;
    for(int i = 0; i < m; ++i){
        scanf("%d", &q);
        minq = min(minq, q);
    }

    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){ 
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end(), greater<int>());

    int sum = 0, d = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
        if(++d == minq){
            d = 0;
            i += 2;
        }
    }
    
    printf("%d\n", sum);
}