#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;


typedef long long LL;


int main(){
    LL s = 0;
    int n, m;
    int t_, T_, x_, c_;
    LL t, T, x, c;
    
    scanf("%d%d", &n, &m);
    for( int i = 0; i < n; ++i ){
        scanf("%d%d%d%d", &t_, &T_, &x_, &c_);
        t = t_; T = T_; x = x_; c = c_;

        LL d = T - t;
        
        if( t + m <= T ){
            s += c;
        }
//      else if(t >= T || c - d * x >= 0 ){
        else if(t >= T ){
            s += c + x * m;
        }
        else{
            LL u = (m + d - 1) / d;
            if( u == 1 ) s += c;
            else{
                LL y = m - (u - 2) * d;
                s += min( min( c + m * x, u * c ), (u - 1) * c + y * x );
            }
        }
    }
    
    cout << s << endl;
}