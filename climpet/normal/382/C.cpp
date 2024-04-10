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
    if(n == 1){
        puts("-1");
        return 0;
    }

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    sort(ALL(a));
    map<int,int> difs;
    for(int i = 1; i < n; ++i){
        ++difs[a[i] - a[i - 1]];
    }

    set<int> ans;
    if(difs.size() == 1){
        int d = difs.begin()->first;
        ans.insert(a[0] - d);
        ans.insert(a.back() + d);
    }
    else if(difs.size() == 2){
        map<int,int>::iterator it1, it2;
        it1 = it2 = difs.begin();
        ++it2;
        if(it1->first < it2->first){
            swap(it1, it2);
        }
        if(it2->first * 2 == it1->first && it1->second == 1){
            for(int i = 1; i < n; ++i){
                if(a[i] - a[i - 1] == it1->first){
                    ans.insert(a[i] - it2->first);
                }
            }
        }
    }
    
    if(n == 2 && (a[0] + a[1]) % 2 == 0){
        ans.insert((a[0] + a[1]) / 2);
    }

    printf("%d", (int)ans.size());
    char spl = '\n';
    for(set<int>::iterator it = ans.begin(); it != ans.end(); ++it){
        printf("%c%d", spl, *it);
        spl = ' ';
    }
    puts("");
}