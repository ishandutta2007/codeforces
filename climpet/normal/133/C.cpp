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
    string s;
    getline(cin, s);

    int a = 0;
    for(int i = 0; i < s.size(); ++i){
        string t = bitset<8>(s[i]).to_string();
        reverse(t.begin(), t.end());
        int b = strtol(t.c_str(), 0, 2);
        printf("%d\n", a - b & 255);
        a = b;
    }
}