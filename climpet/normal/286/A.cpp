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
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        a[i] = i + 1;
    }
    
    if(n % 4 > 1){
        a.assign(1, -1);
    }
    else if(n > 2){
        int k = n - 1;
        for(int i = 0; i < k; i += 2, k -= 2){
            swap(a[i], a[i+1]);
            swap(a[i+1], a[k]);
            swap(a[k], a[k-1]);
        }
    }
    
    for(int i = 0; i < a.size(); ++i){
        if(i != 0){ putchar(' '); }
        printf("%d", a[i]);
    }
    puts("");
}