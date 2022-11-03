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

int a[100000];
int b[100000];
int n;

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    for (int i=0;i<n;i++)
        if (a[i]!=b[i])cnt++;
    if (cnt<=2)
       cout << "YES";
    else
        cout << "NO";
    cout << endl;
   // system("pause");
    return 0;
}