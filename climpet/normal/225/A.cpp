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

int main(){
    int n, x, a[100], b[100];
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &a[i], &b[i]);
    }
    
    bool f = true;
    
    int t = 7 - x;
    for(int i = 1; i < n; ++i){
        bool u[7] = {};
        u[t] = true;
        u[a[i]] = u[7-a[i]] = true;
        u[b[i]] = u[7-b[i]] = true;
        
        int p = -1;
        for(int j = 1; j <= 6; ++j){
            if( !u[j] ){
                if( p == -1 ) p = j;
                else f = false;
            }
        }
    }
    
    puts( f ? "YES" : "NO" );
}