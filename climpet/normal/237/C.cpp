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


bool np[1000005];

int main(){
    for(int i = 2; i < 1000; ++i){
        if( !np[i] ){
            for(int j = i * i; j <= 1000000; j += i){
                np[j] = true;
            }
        }
    }
    
    vector<int> p;
    for(int i = 2; i < 999999; ++i){
        if( !np[i] ){
            p.push_back(i);
        }
    }

    int a, b, k;
    cin >> a >> b >> k;
    int c = lower_bound(p.begin(), p.end(), a) - p.begin();
    int d = upper_bound(p.begin(), p.end(), b) - p.begin() - 1;

    int e = c + k - 1;
    if( e > d ){
        cout << "-1\n";
        return 0;
    }

    int L = max(p[e] - a + 1, b - p[d-k+1] + 1);
    for(int i = e + 1; i <= d; ++i){
        L = max(L, p[i] - p[i-k]);
    }
    
    cout << L << endl;
}