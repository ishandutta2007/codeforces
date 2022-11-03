#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    int a1, a2, a3, b1, b2, b3, n;
    
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    
    int a = a1 + a2 + a3;
    int b = b1 + b2 + b3;
    
    int m = a / 5;
    if (m * 5 < a) ++m;
    
    int k = b / 10;
    if (k * 10 < b) ++k;
    
    if (k + m <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    

    return 0;
}