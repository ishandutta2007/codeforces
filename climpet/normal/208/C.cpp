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
    int n, m;
    int u, v;
    scanf("%d%d", &n, &m );
    
    vector<vector<int> > roads( n + 1 );
    
    for( int i = 0; i < m; ++i ){
        scanf("%d%d", &u, &v );
        roads[u].push_back(v);
        roads[v].push_back(u);
    }
    
    vector<LL> mins( n + 1 );
    vector<int> mintm( n + 1, -1 );
    
    vector<vector<int> > froms( n + 1 );
    
    queue<int> q;
    
    mins[1] = 1;
    mintm[1] = 0;
    int t = 1;
    q.push(1);
    q.push(-1);
    
    while( q.size() > 1 ){
        v = q.front();
        q.pop();
        
        if( v == -1 ){
            ++t;
            q.push( -1 );
            continue;
        }
        
        if( v == n ) break;

        for( int i = 0; i < roads[v].size(); ++i ){
            int to = roads[v][i];
            if( mintm[to] == -1 ){
                mintm[to] = t;
                mins[to] = mins[v];
                q.push( to );
                
                froms[to].push_back(v);
            }
            else if( mintm[to] == t ){
                mins[to] += mins[v];
                
                froms[to].push_back(v);
            }
        }
    }
    
    vector<LL> cnts(n + 1);
    cnts[n] = mins[n];

    q = queue<int>();
    q.push( n );
    while( !q.empty() ){
        v = q.front();
        q.pop();

        LL s = 0;
        for( int i = 0; i < froms[v].size(); ++i ){
            s += mins[ froms[v][i] ];
        }
        for( int i = 0; i < froms[v].size(); ++i ){
            u = froms[v][i];
            if( cnts[u] == 0 ){
                cnts[u] = cnts[v] / s * mins[u];
                q.push( u );
            }
            else{
                cnts[u] += cnts[v] / s * mins[u];
            }
        }
    }
    
    int maxi = 0;
    for( int i = 2; i < n; ++i ){
        if( cnts[maxi] < cnts[i] ) maxi = i;
    }
    
    if( maxi == 0 ){
        printf("%.15f\n", 1.0 );
        return 0;
    }
    else{
        printf("%.15f\n", max( 1.0, 2.0 / mins[n] * cnts[maxi] ) );
    }

}