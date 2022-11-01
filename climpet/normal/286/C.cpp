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

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



int main(){
    int n, t, q;
    scanf("%d", &n);
    vint p(n);
    vector<char> neg(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &p[i]);
    }
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d", &q);
        neg[q-1] = 1;
    }

    stack<int> st;
    vint ans = p;
    for(int i = n - 1; i >= 0; --i){
        if(!st.empty() && !neg[i] && p[st.top()] == p[i]){
            ans[st.top()] = -ans[st.top()];
            st.pop();
        }
        else{
            st.push(i);
        }
    }
    
    if(st.empty()){
        puts("YES");
        for(int i = 0; i < n; ++i){
            if(i != 0){ putchar(' '); }
            printf("%d", ans[i]);
        }
        puts("");
    }
    else{
        puts("NO");
    }
}