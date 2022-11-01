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
#include <fstream>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


#define MOD 1000000009LL


int main(){
//*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
/*/
    ifstream in("input.txt");
    ofstream out("output.txt");
//*/
    
    int n;
    scanf("%d", &n);
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &c[i]);
    }
    sort(c.begin(), c.end());

    int ans = n;
    for(int i = 0; i < n; ++i){
        int k = upper_bound(c.begin(), c.end(), 2 * c[i]) - c.begin();
        ans = min(ans, i + n - k);
    }
    printf("%d\n", ans);
}