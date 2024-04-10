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
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;


int main(){
    int n, m, l, r, x;
    scanf("%d%d", &n, &m);
    
    map<int,int> mp;
    map<int,int>::iterator mit;
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);

        if( x <= n ){
            a[i] = x;
            ++mp[x];
        }
    }

    int k = 0;
    for(mit = mp.begin(); mit != mp.end();){
        if( mit->first <= mit->second ){
            mit->second = k++;
            ++mit;
        }
        else{
            mp.erase(mit++);
        }
    }

    vector<int> keys;
    keys.reserve(k);
    for(mit = mp.begin(); mit != mp.end(); ++mit){
        keys.push_back(mit->first);
    }

    vector<vector<int> > cnt(n + 1, vector<int>(k));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            cnt[i][j] = cnt[i - 1][j];
        }
        
        mit = mp.find(a[i]);
        if(mit != mp.end()){
            ++cnt[i][mit->second];
        }
    }

    for(; m--; ){
        scanf("%d%d", &l, &r);
        --l;

        int s = 0;
        for(int i = 0; i < k; ++i){
            if( cnt[r][i] - cnt[l][i] == keys[i] ){
                ++s;
            }
        }
        printf("%d\n", s);
    }

}