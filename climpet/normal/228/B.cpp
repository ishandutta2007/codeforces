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


bitset<50> a[50], b[50];

int main(){
    int na, ma, nb, mb;
    cin >> na >> ma;
    string str;
    for(int i = 0; i < na; ++i){
        cin >> str;
        str.resize(50, '0');
        a[i] = bitset<50>(str);
    }

    cin >> nb >> mb;
    for(int i = 0; i < nb; ++i){
        cin >> str;
        str.resize(50, '0');
        b[i] = bitset<50>(str);
    }

    int maxx = 0, maxy = 0, maxc = -1;
    for(int x = -50; x <= 50; ++x)
    for(int y = -50; y <= 50; ++y){
        int c = 0;
        int last = min(50, 50 - x);
        for(int i = max(-x, 0); i < last; ++i){
            if( y >= 0 ){
                c += ((a[i] >> y) & b[i + x]).count();
            }
            else{
                c += ((a[i] << -y) & b[i + x]).count();
            }
        }

        if( maxc < c ){
            maxc = c;
            maxx = x;
            maxy = y;
        }
    }
    
    cout << maxx << ' ' << maxy << '\n';
}