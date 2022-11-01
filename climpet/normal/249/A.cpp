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


typedef complex<double> P;

double cross(P a, P b){
    return real(a) * imag(b) - imag(a) * real(b);
}

double distance_l_p(P a, P b, P c) {
    return abs(cross(b-a, c-a)) / abs(b-a);
}

P intersection_l(P a1, P a2, P b1, P b2) {
    P a = a2 - a1; P b = b2 - b1;
    return a1 + a * cross(b, b1-a1) / cross(b, a);
}


int main(){
    double y1, y2, yw, xb, yb, r;
    scanf("%lf%lf%lf%lf%lf%lf", &y1, &y2, &yw, &xb, &yb, &r);
    yw -= r;

    double yt = y1 + r;
    double yt2 = 2.0 * yw - yt;
    P from(xb, yb);
    P to(0.0, yt2);
    P w = intersection_l(from, to, P(0.0, yw), P(1.0, yw));

    P pc(0.0, 2.0 * yw - y2);
    if( distance_l_p(from, to, pc) < r + EPS ){
        puts("-1");
        return 0;
    }
    
    printf("%.13f\n", real(w));
}