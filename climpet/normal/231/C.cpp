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


int main(){
    map<int,int> mp;
    int n, k, a;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        ++mp[a];
    }
    
    vector<pii> v(mp.begin(), mp.end());

    int sz = v.size();
    int c = 0;
    int t = k;
    int x = sz - 1;
    
    int ans = -1;
    int maxc = -1;
    
    v.push_back( pii(v[sz-1].first, 0) );

    for(int i = sz - 1; i >= 0; --i){
        c -= v[i+1].second;
        t += c * (v[i+1].first - v[i].first);
        
        if( i == x ){
            c = v[i].second;
            --x;
        }

        for(; x >= 0; --x ){
            if( i == x ){ continue; }

            int d = min(v[x].second, t / (v[i].first - v[x].first));

            if( d < v[x].second ){
                if( maxc <= c + d ){
                    maxc = c + d;
                    ans = v[i].first;
                }
                break;
            }
            else{
                c += d;
                t -= d * (v[i].first - v[x].first);
            }
        }

        if( maxc <= c ){
            maxc = c;
            ans = v[i].first;
        }
    }
    
    printf("%d %d\n", maxc, ans);
}