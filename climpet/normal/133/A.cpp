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
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}