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
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    
    vector<pii> v;
    for(int i = a; i <= x; ++i)
    for(int j = b; j <= y; ++j){
        if( i > j ){
            v.push_back( pii(i, j) );
        }
    }
    
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); ++i){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}