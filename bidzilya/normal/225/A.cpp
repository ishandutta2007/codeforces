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
    int n;
    cin >> n;
    int x;
    cin >> x;
    int l,r;
    cin >> l >> r;
    x = 7-x;
    int l1,r1;
    for (int i=1;i<n;i++){
        cin >> l >> r;
        l1 = 7-l;
        r1 = 7-r;
        if (x==l1 || x==r1 || x==l || x==r){
           cout << "NO" << endl;
          // system("pause");
           return 0;
        }
    }
    cout << "YES" << endl;    
  //  system("pause");
    return 0;
}