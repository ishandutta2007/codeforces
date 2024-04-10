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

const int of = 80;

int c[of * 2 + 1][of * 2 + 1];
bool f[of * 2 + 1][of * 2 + 1];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    c[of][of] = n;
    vector<int> v1, v2;
    if(n > 3){ v1.push_back(of << 16 | of); }

    int mx = 0;

    bool flag = true;
    while(flag){
        flag = false;
        v2.clear();

        for(int i = 0; i < v1.size(); ++i){
            int y = v1[i] >> 16 & 0xffff;
            int x = v1[i] & 0xffff;
            if(c[y][x] < 4){ continue; }

            int k = c[y][x] >> 2;
            c[y][x] -= k * 4;
            flag = true;
            for(int j = 0; j < 4; ++j){
                int ny = y + dy[j], nx = x + dx[j];
                c[ny][nx] += k;
                mx = max(mx, nx);
                if(c[ny][nx] > 3 && !f[ny][nx]){
                    f[ny][nx] = true;
                    v2.push_back(ny << 16 | nx);
                }
            }
        }
        
        v1.swap(v2);
        memset(f, 0, sizeof f);
    }

    int qy, qx;
    for(int i = 0; i < t; ++i){
        scanf("%d%d", &qx, &qy);
        int res = 0;
        if(abs(qx) < of - 1 && abs(qy) < of - 1){
            res = c[qx + of][qy + of];
        }
        printf("%d\n", res);
    }
}