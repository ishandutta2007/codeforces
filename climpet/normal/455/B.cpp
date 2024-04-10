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
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8


typedef map<char,int> mci;

vector<mci> trie(1);

int dfs(int u, bool p){
    if(trie[u].empty()){
        if(p){
            return 1;
        }
        else{
            return 2;
        }
    }

    int r;
    if(p){
        r = 3;
    }
    else{
        r = 0;
    }
    

    for(auto v : trie[u]){
        int t = dfs(v.second, !p);
        
        if(p){
            if(~t & 2){
                r &= ~2;
            }
            if(~t & 1){
                r &= ~1;
            }
        }
        else{
            if(t & 1){
                r |= 1;
            }
            if(t & 2){
                r |= 2;
            }
        }
    }
    return r;
}


int main(){
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        int v = 0;
        for(char c : s){
            if(trie[v].count(c)){
                v = trie[v][c];
            }
            else{
                int t = trie.size();
                trie[v][c] = t;
                trie.push_back(mci());
                v = t;
            }
        }
    }

    int r = dfs(0, 0);

    bool win = true;
    if(r == 0){
        win = false;
    }
    else if(r == 1){
        win = k & 1;
    }
    else if(r == 2){
        win = false;
    }
    
    puts(win ? "First" : "Second");
}