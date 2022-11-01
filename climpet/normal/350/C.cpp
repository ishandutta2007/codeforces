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


vector<string> res;

void moveto(int x, int y){
    static char buf[64];

    if(x > 0){
        sprintf(buf, "1 %d R\n", x);
        res.push_back(buf);
    }
    else if(x < 0){
        sprintf(buf, "1 %d L\n", -x);
        res.push_back(buf);
    }
    if(y > 0){
        sprintf(buf, "1 %d U\n", y);
        res.push_back(buf);
    }
    else if(y < 0){
        sprintf(buf, "1 %d D\n", -y);
        res.push_back(buf);
    }
}


typedef complex<LL> P;
bool cmp(const P &a, const P &b){
    return norm(a) < norm(b);
}


int main(){
    int n, x, y;
    scanf("%d", &n);

    vector<P> v(n);
    REP(i, n){
        scanf("%d%d", &x, &y);
        v[i] = P(x, y);
    }

    sort(ALL(v), cmp);

    REP(i, n){
        x = real(v[i]);
        y = imag(v[i]);
        scanf("%d%d", x, &y);
        moveto(x, y);
        res.push_back("2\n");
        moveto(-x, -y);
        res.push_back("3\n");
    }

    cout << res.size() << '\n';
    for(size_t i = 0; i < res.size(); ++i){
        cout << res[i];
    }
}