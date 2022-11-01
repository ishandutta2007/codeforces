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
#include <iterator>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;



int main(){
    int n, k;
    int r[205];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 2 * n + 1; ++i){
        scanf("%d", &r[i] );
    }

    for(int i = 1; k; i += 2 ){
        if( r[i] > r[i-1] + 1 && r[i] > r[i+1] + 1 ){
            --r[i];
            --k;
        }
    }

    printf("%d", r[0]);
    for(int i = 1; i < 2 * n + 1; ++i){
        printf(" %d", r[i]);
    }
    puts("");
}