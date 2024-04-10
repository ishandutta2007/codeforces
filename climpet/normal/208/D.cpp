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

using namespace std;


typedef long long LL;


int main(){
    int n;
    cin >> n;

    vector<LL> pts(n);
    for( int i = 0; i < n; ++i ) cin >> pts[i];

    vector<LL> costs(5);
    for( int i = 0; i < 5; ++i ) cin >> costs[i];

    vector<LL> counts(5);
    
    LL spt = 0;

    int k = 0;
    while( k < n ){
        spt += pts[k];

        while( spt >= costs[0] ){
            int j = 4;
            for( ; j > 0 && spt < costs[j]; --j );
            counts[j] += spt / costs[j];
            spt %= costs[j];
        }
        ++k;
    }
    
    for( int i = 0; i < 4; ++i ){
        cout << counts[i] << ' ';
    }
    cout << counts[4] << '\n' << spt << endl;
}