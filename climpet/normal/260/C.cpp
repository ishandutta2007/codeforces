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
    int n, x;
    scanf("%d%d", &n, &x);
    --x;

    vector<LL> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%I64d", &a[i]);
    }
    LL sum = accumulate(a.begin(), a.end(), 0LL);
    LL minvalue = *min_element(a.begin(), a.end());

    int k;
    for(k = x; a[k] != minvalue; k = (k - 1 + n) % n);
    LL u = a[k];
    LL t = n * u + (x - k + n) % n;

    for(int i = 0; i < n; ++i){
        a[i] -= u;
    }
    for(int i = k; ; i = (i + 1) % n){
        --a[i];
        if(i == x) break;
    }
    a[k] = t;

    for(int i = 0; i < n; ++i){
        if(i != 0) putchar(' ');
        printf("%I64d", a[i]);
    }
    puts("");
}