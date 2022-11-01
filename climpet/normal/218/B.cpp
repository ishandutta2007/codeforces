#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(m);
    for(int i = 0; i < m; ++i){
        scanf("%d", &a[i]);
    }
    
    int r1 = 0, r2 = 0;

    multiset<int,greater<int> > s(a.begin(), a.end());
    multiset<int,greater<int> >::iterator it;
    for(int k = n; k; --k){
        it = s.begin();
        int t = *it;
        r1 += t;
        s.erase(it);
        s.insert(t - 1);
    }

    sort(a.begin(), a.end());
    int j = 0;
    for(int k = n; k; --k){
        if( !a[j] ) ++j;
        r2 += a[j];
        --a[j];
    }
    
    printf("%d %d\n", r1, r2);
}