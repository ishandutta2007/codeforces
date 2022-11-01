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


#define MOD 1000003
#define EPS 1e-8


int main(){
    string t = "><+-.,[]";
    string s, a;
    cin >> s;

    for(int i = 0; i < s.size(); ++i){
        a += bitset<4>(t.find(s[i]) | 8).to_string();
    }

    int ans = 0;
    for(int i = 0; i < a.size(); ++i){
        ans = (ans * 2 + (a[i] - '0')) % MOD;
    }
    printf("%d\n", ans);
}