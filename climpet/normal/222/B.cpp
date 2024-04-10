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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    
    vector<vector<int> > a(n, vector<int>(m) );
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    
    vector<int> rs(n), cs(m);
    for(int i = 0; i < n; ++i) rs[i] = i;
    for(int i = 0; i < m; ++i) cs[i] = i;
    
    char s;
    int x, y;
    for(int h = 0; h < k; ++h){
        scanf(" %c%d%d", &s, &x, &y);
        --x;
        --y;
        
        if( s == 'c' ){
            swap(cs[x], cs[y]);
        }
        else if( s == 'r' ){
            swap(rs[x], rs[y]);
        }
        else{
            printf("%d\n", a[rs[x]][cs[y]]);
        }
    }
}