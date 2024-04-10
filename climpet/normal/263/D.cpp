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


int rank[100001], par[100001];
int find(int x){
    return x != par[x] ? par[x] = find(par[x]) : x;
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        if(rank[x] < rank[y]){
            par[x] = y;
        }
        else{
            par[y] = x;
            if(rank[x] == rank[y]) ++rank[x];
        }
    }
}


vector<vector<int> > G;
vector<pii> E;
int n, k;
stack<int> ans;
bool visit[100001];
int start;

void func(){
    visit[ans.top()] = true;
    if(ans.size() > k && binary_search(E.begin(), E.end(), pii(start, ans.top()))){
        printf("%d", ans.size());
        char c = '\n';
        while(!ans.empty()){
            printf("%c%d", c, ans.top() + 1);
            ans.pop();
            c = ' ';
        }
        puts("");
        exit(0);
    }

    vector<int> &edge = G[ans.top()];
    int t = edge.size();
    while(t > 0){
        int u = rand() % t;
        swap(edge[--t], edge[u]);
        if(!visit[edge[t]]){
            ans.push(edge[t]);
            func();
        }
    }
    visit[ans.top()] = false;
    ans.pop();
}

int main(){
    srand(time(0));
    int m, a, b;
    scanf("%d%d%d", &n, &m, &k);
    G.resize(n + 1);
    for(int i = 0; i < n; ++i){
        par[i] = i;
    }
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
        unite(a, b);
        E.push_back( pii(a, b) );
        E.push_back( pii(b, a) );
    }
    sort(E.begin(), E.end());

    vector<int> bel(n);
    for(int i = 0; i < n; ++i){
        ++bel[find(i)];
    }
    int t = max_element(bel.begin(), bel.end()) - bel.begin();
    ans.push(t);
    start = t;
    func();

    throw 1;
}