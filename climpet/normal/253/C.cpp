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
#include <fstream>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


#define MOD 1000000009LL


int main(){
//*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
/*/
    ifstream in("input.txt");
    ofstream out("output.txt");
//*/
    
    int n, r1, r2, c1, c2;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    --r1;
    --r2;
    --c1;
    --c2;

    vector<int> as = a;
    as.push_back(0);
    as.push_back(c1);
    as.push_back(c2);

    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        b[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
    }

    vector<vector<pii> > es(n * as.size());
    int t = 0;
    int m = as.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < as.size(); ++j, ++t){
            if(j > b[i]) continue;

            if(j != 0){
                es[t].push_back( pii(as[j] - as[j-1], i * m + (j - 1)) );
            }

            if(j < b[i]){
                es[t].push_back( pii(as[j+1] - as[j], i * m + (j + 1)) );
            }

            if(i != 0){
                es[t].push_back( pii(1, (i - 1) * m + min(j, b[i-1]) ) );
            }

            if(i + 1 != n){
                es[t].push_back( pii(1, (i + 1) * m + min(j, b[i+1]) ) );
            }
        }
    }

    vector<int> dist(n * m, INT_MAX);

    int ic1 = lower_bound(as.begin(), as.end(), c1) - as.begin();
    int ic2 = lower_bound(as.begin(), as.end(), c2) - as.begin();
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push( pii(0, r1 * m + ic1) );
    dist[r1 * m + ic1] = 0;
    
    int d = r2 * m + ic2;

    while(1){
        pii p = pq.top();
        pq.pop();
        int c = p.first;
        int v = p.second;
        if(c != dist[v]) continue;

        if(v == d){
            printf("%d\n", c);
            return 0;
        }

        for(int i = 0; i < es[v].size(); ++i){
            pii p2(c + es[v][i].first, es[v][i].second);
            if( dist[p2.second] > p2.first ){
                dist[p2.second] = p2.first;
                pq.push(p2);
            }
        }
    }
}