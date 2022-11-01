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
    int n, d, L;
    cin >> n >> d >> L;

    vector<int> a(n, 1);
    int x = d;

    if( n % 2 ){
        a[n - 1] = max(1, min(d, L));
        x -= a[n - 1];
    }

    for(int i = 0; i + 1 < n && x != 0; i += 2){
        if( x > 0 ){
            a[i] = min(x + 1, L);
        }
        else{
            a[i + 1] = min(-x + 1, L);
        }
        
        x -= a[i] - a[i + 1];
    }

    if( x != 0 ){
        cout << "-1\n";
        return 0;
    }
    
    for(int i = 0; i < n; ++i){
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}