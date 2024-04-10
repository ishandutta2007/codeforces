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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


char a[1010][1010];
int dst[1010][1010];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    memset(dst, -1, sizeof dst);

    int r, c;
    scanf("%d%d", &r, &c);
    queue<int> q;
    for(int i = 1; i <= r; ++i){
        scanf(" %s", a[i] + 1);
        for(int j = 1; j <= c; ++j){
            if(a[i][j] == 'E'){
                q.push(i << 16 | j);
                dst[i][j] = 0;
            }
        }
    }
    q.push(-1);
    int tm = 1;
    int s = -1;
    while(q.size() > 1){
        if(q.front() == -1){
            ++tm;
            q.push(-1);
        }
        else{
            int y = q.front() >> 16;
            int x = q.front() & 0xffff;
            for(int i = 0; i < 4; ++i){
                int ny = y + dy[i], nx = x + dx[i];
                if(dst[ny][nx] == -1 && a[ny][nx] && a[ny][nx] != 'T'){
                    q.push(ny << 16 | nx);
                    dst[ny][nx] = tm;
                    
                    if(a[ny][nx] == 'S'){
                        s = tm;
                    }
                }
            }
        }
        q.pop();
    }
    
    int ans = 0;
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        if(dst[i][j] != -1 && dst[i][j] <= s && isdigit(a[i][j])){
            ans += a[i][j] - '0';
        }
    }
    printf("%d\n", ans);
}