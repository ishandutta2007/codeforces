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


int par[100];
int rank[100];

void init(int n){
    for(int i = 0; i < n; ++i){
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x){
    if( par[x] != x ){
        par[x] = find(par[x]);
    }
    return par[x];
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if( x == y ) return;
    
    if( rank[x] < rank[y] )
        par[x] = y;
    else{
        par[y] = x;
        if( rank[x] == rank[y] ) ++rank[x];
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int x[100], y[100];
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }

    init(n);

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(x[i] == x[j] || y[i] == y[j]){
                unite(i, j);
            }
        }
    }

    for(int i = 0; i < n; ++i) find(i);

    printf("%d\n", set<int>(par, par + n).size() - 1);
}