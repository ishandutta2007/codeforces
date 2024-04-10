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


inline double sq(int x){
    return x * x;
}


int main(){
    int n, m, k;
    int a, b;

    scanf("%d", &n);
    vector<int> x(n);
    for( int i = 0; i < n; ++i ){
        scanf("%d", &x[i] );
    }
    
    scanf("%d", &m);
    vector<int> y(m);
    for( int i = 0; i < m; ++i ){
        scanf("%d", &y[i] );
    }
    
    scanf("%d", &k);
    int p2 = 1e9;
    int u;
//  vector<int> z(k);
    for( int i = 0; i < k; ++i ){
//      scanf("%d", &z[i] );
        scanf("%d", &u);
        p2 = min( p2, u );
    }

    scanf("%d%d", &a, &b );


    vector<int>::iterator r1, p1;//, p2;
    double s2 = 0;

    for( r1 = x.begin(); r1 != x.end(); ++r1 )
    for( p1 = y.begin(); p1 != y.end(); ++p1 )
//  for( p2 = z.begin(); p2 != z.end(); ++p2 ){
    {
        s2 = max(s2, sq(*r1) * (b * *p1) / (b * *p1 + a * p2) );
    }
    
    printf("%.10f\n", sqrt(s2) );
}