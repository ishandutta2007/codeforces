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
    int a[50], b[50];

    int maxr = 0;
    int cnt = 0;
    
    int n, m;
    scanf("%d", &n);
    for( int i = 0; i < n; ++i ){
        scanf("%d", &a[i] );
    }
    scanf("%d", &m);
    for( int i = 0; i < m; ++i ){
        scanf("%d", &b[i] );
    }

    for( int i = 0; i < n; ++i ){
        for( int j = 0; j < m; ++j ){
            if( b[j] % a[i] == 0 ){
                if( b[j] / a[i] > maxr ){
                    maxr = b[j] / a[i];
                    cnt = 1;
                }
                else if( b[j] / a[i] == maxr ){
                    ++cnt;
                }
            }
        }
    }
    
    printf("%d\n", cnt );
}