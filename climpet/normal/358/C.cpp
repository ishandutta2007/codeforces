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



int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n + 5);
    vector<int> tp(n + 5, 3);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int p = 0;
    vector<pii> v;
    for(int i = 0; i <= n; ++i){
        if(a[i] == 0){
            tp[i] = -1;
            v.assign(3, pii(-1, n + 2));
            for(int j = p; j < i; ++j){
                v.push_back(pii(a[j], j));
            }
            sort(RALL(v));

            tp[v[0].second] = 0;
            tp[v[1].second] = 1;
            tp[v[2].second] = 2;
            
            p = i + 1;
        }
    }
    
    const char *popmsg[3] = {
        "popStack", "popQueue", "popFront"
    };
    const char *pushmsg[4] = {
        "pushStack", "pushQueue", "pushFront", "pushBack"
    };

    vector<int> st(5, -1);
    for(int i = 0; i < n; ++i){
        if(tp[i] == -1){
            int k = 3 - count(st.begin(), st.begin() + 3, -1);
            printf("%d", k);
            for(int j = 0 ; j < 3; ++j){
                if(st[j] != -1){
                    printf(" %s", popmsg[j]);
                    st[j] = -1;
                }
            }
            puts("");
        }
        else{
            puts(pushmsg[tp[i]]);
            st[tp[i]] = a[i];
        }
    }
}