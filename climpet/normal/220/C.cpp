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
    int n, x;
    scanf("%d", &n);

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        a[i] = x - 1;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        b[i] = x - 1;
    }

    vector<int> pos(n);
    vector<int> dif(n);
    for(int i = 0; i < n; ++i){
        pos[a[i]] = i;
    }
    for(int i = 0; i < n; ++i){
        dif[i] = i - pos[b[i]];
    }

    typedef multiset<int>::iterator msitr;
    vector<msitr> vitr(n);
    multiset<int> ms;

    for(int i = 0; i < n; ++i){
        vitr[i] = ms.insert(dif[i]);
    }
    ms.insert(-1e8);
    ms.insert(1e8);
    

    msitr it, it2;
    for(int i = 0; i < n; ++i){
        it2 = it = ms.lower_bound(i);
        --it2;
        printf("%d\n", min( abs(*it - i), abs(*it2 - i) ) );

        it = vitr[i];
        x = *it;
        ms.erase(it);
        vitr[i] = ms.insert(x + n);
    }
}