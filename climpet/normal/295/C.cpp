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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000007
#define EPS 1e-8

int cmb[51][51];

int main(){
    for(int i = 0; i <= 50; ++i){
        cmb[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            cmb[i][j] = (cmb[i-1][j-1] + cmb[i-1][j]) % MOD;
        }
    }

    int n, k, a, c[3] = {};
    scanf("%d%d", &n, &k);
    k /= 50;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        ++c[a / 50];
    }

    vint visit(1 << 13, -1);
    vLL cnt(1 << 13);
    queue<int> q;
    q.push(c[1] << 7 | c[2] << 1);
    visit[q.front()] = 0;
    cnt[q.front()] = 1;
    q.push(-1);
    int step = 0;
    while(q.size() > 1){
        int now = q.front();
        q.pop();
        if(now == 1){
            cout << step << '\n' << cnt[1] << endl;
            return 0;
        }
        if(now == -1){
            q.push(-1);
            ++step;
            continue;
        }

        int a = now >> 7;
        int b = now >> 1 & 63;
        if(now & 1){
            a = c[1] - a;
            b = c[2] - b;
        }

        for(int i = 0; i <= a; ++i){
            for(int j = 0; j <= b && i + 2 * j <= k; ++j){
                if(!i && !j){ continue; }

                int x, y;
                if(now & 1){
                    x = (now >> 7) + i;
                    y = (now >> 1 & 63) + j;
                }
                else{
                    x = a - i;
                    y = b - j;
                }
                int nxt = x << 7 | y << 1 | (~now & 1);

                if(visit[nxt] == -1){
                    visit[nxt] = step;
                    q.push(nxt);
                }
                if(visit[nxt] == step){
                    LL add = cnt[now] * cmb[a][i] % MOD * cmb[b][j];
                    cnt[nxt] = (cnt[nxt] + add) % MOD;
                }
            }
        }
    }
    cout << "-1\n0\n";
}