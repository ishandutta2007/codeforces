#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

int main(){
    int xa,xb,xc,ya,yb,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int v1x,v1y,v2x,v2y;
    v1x = xb-xa;
    v2x = xc-xb;
    v1y = yb-ya;
    v2y = yc-yb;
    ll det = 1LL*v1x*v2y-1LL*v2x*v1y;
    if (det==0)cout << "TOWARDS";
    if (det<0)cout << "RIGHT";
    if (det>0)cout << "LEFT";
    cout << endl;


  //  system("pause");
    return 0;
}