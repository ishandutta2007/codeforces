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
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int h, w;
char fl[2048][2048];
int ds[2048][2048];
int to[2048][2048];

void dfs(int y, int x){
    if(to[y][x] == -9){
        throw 0;
    }
    if(to[y][x] != -1){ return; }

    if(fl[y][x] == '#'){
        to[y][x] = y << 16 | x;
        ds[y][x] = 0;
    }
    else{
        int ny = y, nx = x;
        switch(fl[y][x]){
        case '^':
            --ny;
            break;
        case 'v':
            ++ny;
            break;
        case '<':
            --nx;
            break;
        case '>':
            ++nx;
            break;
        }

        to[y][x] = -9;
        dfs(ny, nx);
        if(ds[ny][nx]){
            to[y][x] = to[ny][nx];
        }
        else{
            to[y][x] = y << 16 | x;
        }
        ds[y][x] = ds[ny][nx] + 1;
    }
}


int main(){
    memset(to, -1, sizeof to);

    scanf("%d%d", &h, &w);
    for(int i = 0; i < h; ++i){
        scanf(" %s", fl[i]);
    }

    int ans = -1;
    try{
        for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            if(to[i][j] == -1){
                dfs(i, j);
            }
        }

        int md = *max_element(*ds, *ds + sizeof(ds) / sizeof(int));
        set<int> st;
        for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            if(ds[i][j] == md){
                st.insert(to[i][j]);
                if(st.size() == 2){
                    ans = 2 * md;
                    throw 0;
                }
            }
        }

        ans = max(0, 2 * md - 1);
    }
    catch(...){}

    printf("%d\n", ans);
}