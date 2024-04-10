#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
ld a, b, c, d, l = 0, r = 1000000000, mid, eps = 1e-10, eps1= 1e-14, l11, r11, l22, r22, l12, r12, l21, r21, pl1, pl2, pr1, pr2;
int main(){
    //ifstream cin("input.txt");
    cin >> a >> b >> c >> d;
    while(fabs(r - l) > eps){
      mid = (r + l) / 2;
      l11 = min(mid + a, -mid + a);
      r11 = max(mid + a, -mid + a);
      l12 = min(mid + b, -mid + b);
      r12 = max(mid + b, -mid + b);
      l21 = min(mid + c, -mid + c);
      r21 = max(mid + c, -mid + c);
      l22 = min(mid + d, -mid + d);
      r22 = max(mid + d, -mid + d);
      pr1 = max(max(l11 * l22, r11 * r22), max(l11 * r22, r11 * l22));
      pl1 = min(min(l11 * l22, r11 * r22), min(l11 * r22, r11 * l22));
      pr2 = max(max(l12 * l21, r12 * r21), max(l12 * r21, r12 * l21));
      pl2 = min(min(l12 * l21, r12 * r21), min(l12 * r21, r12 * l21));
      if((pl2 >= pl1 && pl2 <= pr1)||(pr2 >= pl1&& pr2 <= pr1) || (pl1 >= pl2 && pl1 <= pr2)){
        r = mid;
      }else l = mid;
    }
    cout.precision(30);
    cout << r;
    return 0;
}