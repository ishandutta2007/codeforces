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
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

bool check(int x,int y){
     int xx[10],yy[10];
     for (int i=0;i<10;i++)
         xx[i]=yy[i]=0;
     while (x>0){
           xx[x%10]++;
           x/= 10;
     }
     while (y>0){
           yy[y%10]++;
           y/= 10;
     }
     for (int i=0;i<10;i++)
         if (xx[i] && yy[i])
            return true;
     return false;
}

int main(){
    int n,cnt=0;
    cin >> n;
    for (int i=1;i<=sqrt(n);i++)
        if (n%i==0){
                    if (check(n,i))cnt++;
                    if (n/i!=i && check(n,n/i))cnt++;
        }
    cout << cnt << endl;
  //  system("pause");
    return 0;
}