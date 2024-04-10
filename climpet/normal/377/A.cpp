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


int h, w, k;
char fs[512][512];
bool visit[512][512];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


void dfs(int y, int x){
    visit[y][x] = true;
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i], nx = x + dx[i];
        if(fs[ny][nx] == '.' && !visit[ny][nx]){
            dfs(ny, nx);
        }
    }
    if(k > 0){
        fs[y][x] = 'X';
        --k;
    }
}


int main(){
    scanf("%d%d%d", &h, &w, &k);
    for(int i = 1; i <= h; ++i){
        scanf(" %s", fs[i] + 1);
    }

    bool fnd = false;
    for(int i = 1; !fnd && i <= h; ++i)
    for(int j = 1; !fnd && j <= w; ++j){
        if(fs[i][j] == '.'){
            dfs(i, j);
            fnd = true;
        }
    }

    for(int i = 1; i <= h; ++i){
        puts(fs[i] + 1);
    }
}