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


int c[50], a[50][50], b[50][50];
int x[2500], y[2500], p[2500], q[2500];
int m;


int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &c[i]);
    }

    vector<int> v;

    map<int,pii> tbl;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < c[i]; ++j){
        scanf("%d", &a[i][j]);
        tbl[a[i][j]] = pii(i, j);
        v.push_back(a[i][j]);
    }

    sort(v.begin(), v.end());
    int t = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < c[i]; ++j){
        b[i][j] = v[t++];
    }

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < c[i]; ++j){
        int k = b[i][j];
        pii p1 = tbl[k];
        if( p1 == pii(i, j) ) continue;

        int u = a[i][j];
        swap(tbl[k], tbl[u]);
        swap(a[i][j], a[p1.first][p1.second]);

        x[m] = i + 1;
        y[m] = j + 1;
        p[m] = p1.first + 1;
        q[m] = p1.second + 1;
        ++m;
    }
    
    printf("%d\n", m);
    for(int i = 0; i < m; ++i){
        printf("%d %d %d %d\n", x[i], y[i], p[i], q[i]);
    }
}