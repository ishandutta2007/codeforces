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


#define MOD 1000000009LL
#define EPS 1e-8

int n;
vector<vector<int> > con;
vector<pii> edge;

void func(int b, int c){
    stack<int> ans;
    ans.push(b);
    ans.push(c);

    vector<char> vis(n);
    vis[0] = vis[b] = vis[c] = true;

    while(ans.size() < n){
        if(ans.size() + 1 == n) vis[0] = false;
        bool f = true;
        for(int i = 0; i < 4 && f; ++i){
            int d = con[c][i];
            if(!vis[d] && binary_search(edge.begin(), edge.end(), pii(b, d))){
                f = false;
                vis[d] = true;
                ans.push(d);
                b = c;
                c = d;
            }
        }
        if(f) return;
    }

    while(1){
        printf("%d", ans.top() + 1);
        ans.pop();
        if(ans.empty()){
            puts("");
            exit(0);
        }
        putchar(' ');
    }
}

int main(){
    int a, b;
    scanf("%d", &n);
    con.resize(n);
    edge.reserve(2 * n);
    for(int i = 2 * n; i--; ){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        con[a].push_back(b);
        con[b].push_back(a);
        edge.push_back( pii(a, b) );
        edge.push_back( pii(b, a) );
    }
    sort(edge.begin(), edge.end());

    for(int i = 0; i < n; ++i){
        if(con[i].size() != 4){
            puts("-1");
            return 0;
        }
    }

    vector<int>::iterator itj, itk;

    for(itj = con[0].begin(); itj != con[0].end(); ++itj)
    for(itk = con[0].begin(); itk != con[0].end(); ++itk){
        if(binary_search(edge.begin(), edge.end(), pii(*itj, *itk))){
            func(*itj, *itk);
        }
    }


    puts("-1");
}