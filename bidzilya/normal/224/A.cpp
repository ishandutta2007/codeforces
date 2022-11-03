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
    int x,y,z;
    int a,b,c;
    cin >> x >> y >> z;
    a = sqrt(x*y/z);
    b = sqrt(x*z/y);
    c = sqrt(y*z/x);
    cout << 4*(a+b+c) << endl;
   // system("pause");
    return 0;
}