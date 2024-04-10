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


#define MOD 1000000009LL
#define EPS 1e-8


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        int c = 0;
        for(int j = 0; j < n; ++j){
            if(a[j] >= a[i]) ++c;
        }
        if(c == k){
            cout << a[i] << " 0\n";
            return 0;
        }
    }
    cout << "-1\n";
}