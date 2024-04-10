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
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;


int main(){
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    vector<int> b = a;
    sort(b.begin(), b.end());

    int s = 0;
    for(int i = 0; i < n; ++i){
        if( a[i] != b[i] ) ++s;
    }

    if( s == 0 || s == 2 ){
        puts("YES");
    }
    else{
        puts("NO");
    }

}