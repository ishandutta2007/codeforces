#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define Inf 2147483647
#define Pi acos(-1.0)
#define LL long long

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Pr(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;
#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int a1, a2, b1, b2, c1, c2;

int main() {
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    
    bool asdf = false;
    
    if (b1+c1 <= a1 && max(b2,c2) <= a2) {
        asdf = true;
    }
    
    if (b1+c1 <= a2 && max(b2,c2) <= a1) {
        asdf = true;
    }
    
    if (b1+c2 <= a1 && max(b2,c1) <= a2) {
        asdf = true;
    }
    
    if (b1+c2 <= a2 && max(b2,c1) <= a1) {
        asdf = true;
    }
    
    if (b2+c1 <= a1 && max(b1,c2) <= a2) {
        asdf = true;
    }
    
    if (b2+c1 <= a2 && max(b1,c2) <= a1) {
        asdf = true;
    }
    
    if (b2+c2 <= a1 && max(b1,c1) <= a2) {
        asdf = true;
    }
    
    if (b2+c2 <= a2 && max(b1,c1) <= a1) {
        asdf = true;
    }
    
    if (asdf == true) {
        cout << "YES" << endl;
    } else if (asdf == false) {
        cout << "NO" << endl;
    }
}