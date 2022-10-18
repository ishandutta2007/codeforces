
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

constant maxn = 50+8;

_ n, s = 1E11;
str a[maxn];
map<str, _> mp;

_ count();
void fill();
int main() {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(_ i = 1; i <= n; ++i) cin >> a[i];
    for(_ i = 2; i <= n; ++i) if(a[i].length() != a[1].length()) {
        puts("-1");
        exit(0);
    }
    for(_ i = 1; i <= 50; ++i) {
        fill();
        s = min(s, count()+i-1);
        a[1] = a[1].substr(1)+a[1].front();
    }
    printf("%lld\n", s);
    
    return 0;
}

void fill() {
    mp.clear();
    str t = a[1];
    for(_ i = 0; i < a[1].length(); ++i) {
        if(!mp.count(t)) mp[t] = i;
        t = t.back()+t;
        t.pop_back();
    }
    return;
}

_ count() {
    _ rv = 0;
    for(_ i = 2; i <= n; ++i) {
        if(!mp.count(a[i])) {
            puts("-1");
            exit(0);
        }
        rv += mp[a[i]];
    }
    return rv;
}