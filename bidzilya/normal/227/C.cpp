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

int n,m;

int pow(int x){
    if (x==0)return 1;
    if (x%2==0){
       int tm = pow(x/2);
       return ((1LL*tm*tm)%m);
    }
    if (x%2==1){
       int tm = pow(x-1);
       return ((3LL*tm)%m);
    }
}

int main(){
    cin >> n >> m;
    ll x = (pow(n)-1)%m;
    if (x<0)x += m;
    cout << x << endl;        
  //  system("pause");
    return 0;
}