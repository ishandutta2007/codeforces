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
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;


vector<vector<int> > edge, redge;
vector<int> ret;

bitset<200001> used;


int countrev(int s){
    int c = 0;
    used[s] = true;

    for(int i = 0; i < edge[s].size(); ++i){
        int v = edge[s][i];
        if( !used[v] ){
            c += countrev(v);
        }
    }
    
    for(int i = 0; i < redge[s].size(); ++i){
        int v = redge[s][i];
        if( !used[v] ){
            c += 1 + countrev(v);
        }
    }
    
    return c;
}


void solve(int s, int c){
    used[s] = true;
    ret[s] = c;

    for(int i = 0; i < edge[s].size(); ++i){
        int v = edge[s][i];
        if( !used[v] ){
            solve(v, c + 1);
        }
    }
    
    for(int i = 0; i < redge[s].size(); ++i){
        int v = redge[s][i];
        if( !used[v] ){
            solve(v, c - 1);
        }
    }
}


int main(){
    int n, s, t;
    scanf("%d", &n);

    edge.resize(n + 1);
    redge.resize(n + 1);
    ret.resize(n + 1, 1e9);

    for(int i = 1; i < n; ++i){
        scanf("%d%d", &s, &t);

        edge[s].push_back(t);
        redge[t].push_back(s);
    }

    int cr = countrev(1);
    used.reset();

//printf("cr: %d\n", cr);

    solve(1, cr);

    int ans = 1e9;
    vector<int> v;
    for(int i = 1; i <= n; ++i){
    
//printf("ret[%d]: %d\n",i,ret[i]);
    
        if( ret[i] == ans ){
            v.push_back(i);
        }
        else if( ret[i] < ans ){
            ans = ret[i];
            v.clear();
            v.push_back(i);
        }
    }

    printf("%d", ans);
    for(int i = 0; i < v.size(); ++i){
        printf("%c%d", i == 0 ? '\n' : ' ', v[i]);
    }
    puts("");
}