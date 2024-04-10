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
    int s, k;
    scanf("%d%d", &s, &k);
    
    vector<int> f;
    f.reserve(100000);

    f.push_back(1);
    int d = 0;
    for(;;){
        int t = 0;
        for(int i = 0; i < k && i < f.size(); ++i){
            t += f[f.size() - 1 - i];
            if( t > s ) break;
        }
        
        if( t > s ) break;
        f.push_back(t);
    }
    
    vector<int> v;
    v.push_back(0);
    int j = f.size() - 1;
    
    while(s > 0){
        if( s >= f[j] ){
            s -= f[j];
            v.push_back( f[j] );
        }
        else{
            --j;
        }
    }
    
    printf("%d\n", v.size());
    for(int i = v.size() - 1; i >= 0; --i)
        printf("%d%c", v[i], i ? ' ' : '\n');
}