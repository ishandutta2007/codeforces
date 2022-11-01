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


int a[100][100];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        scanf("%d", &a[i][j]);
    }
    
    int sums[201] = {};
    int negs[201] = {};

    for(int i = 0; i < n; ++i){
        int s = 0;
        for(int j = 0; j < m; ++j){
            s += a[i][j];
            if( a[i][j] < 0 ){
                ++negs[i];
                ++negs[j + 100];
            }
        }
        sums[i] = s;
    }
    for(int j = 0; j < m; ++j){
        int s = 0;
        for(int i = 0; i < n; ++i){
            s += a[i][j];
        }
        sums[j + 100] = s;
    }

    bool out[200] = {};
    while(true){
        int index = 200;
        for(int i = 0; i < 200; ++i){
            if( sums[i] < 0 && negs[i] > negs[index] ){
                index = i;
            }
        }
        if( index == 200 ) break;
        
        out[index] = !out[index];
        sums[index] = -sums[index];

        if(index < 100){
            negs[index] = n - negs[index];

            for(int j = 0; j < m; ++j){
                a[index][j] = -a[index][j];
                if( a[index][j] < 0 ){
                    ++negs[j + 100];
                }
                else if( a[index][j] > 0 ){
                    --negs[j + 100];
                }
                
                sums[j + 100] += a[index][j] << 1;
            }
        }
        else{
            int t = index - 100;
            negs[index] = m - negs[index];
            for(int i = 0; i < n; ++i){
                a[i][t] = -a[i][t];
                if( a[i][t] < 0 ){
                    ++negs[i];
                }
                else if( a[i][t] > 0 ){
                    --negs[i];
                }
                
                sums[i] += a[i][t] << 1;
            }
        }
    }
    
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 200; ++i){
        if( out[i] ){
            if( i < 100 ){ ++c1; }
            else{ ++c2; }
        }
    }
    
    printf("%d", c1);
    for(int i = 0; i < 100; ++i){
        if( out[i] ){
            printf(" %d", i + 1);
        }
    }
    printf("\n%d", c2);
    for(int i = 100; i < 200; ++i){
        if( out[i] ){
            printf(" %d", i - 99);
        }
    }
    puts("");
}