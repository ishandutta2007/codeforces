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

using namespace std;


typedef long long LL;


int r, n, m;
vector<int> ar[101];
bool check[101];

int par[101];
int rank[101];


int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    
    if( rank[x] < rank[y]){
        par[x]=y;
    }
    else{
        par[y] = x;
        if(rank[x]==rank[y])++rank[x];
    }
}



int main(){
    int a, b;
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; ++i){
        par[i] = i;
    }
    
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        ar[a].push_back(b);
        ar[b].push_back(a);

        unite(a, b);
    }

    for(int i=1;i<=n;++i)find(i);

    for(int i = 1; i <= n; ++i ){
        int p = par[i];
        if( !check[p] ){
            check[p] = true;

            bool flag = true;
            int c = 0;
            for(int j = i; j <= n; ++j){
                if( par[j] == p ){
                    ++c;
                    
                    if( ar[j].size() != 2 )
                        flag = false;
                }
            }
            if( c % 2 && flag ) ++r;
        }
    }

    if( (n - r) % 2 ) ++r;
    printf("%d\n", r);
}