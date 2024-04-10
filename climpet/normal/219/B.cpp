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

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;


int main(){
    LL p, d;
    cin >> p >> d;

    for( LL a = 1; a <= p && d > 0; a *= 10 ){
        LL b = (1 + p / a % 10) % 10 * a;

        if( b > d ){
            break;
        }

        p -= b;
        d -= b;
    }
    
    cout << p << endl;
}