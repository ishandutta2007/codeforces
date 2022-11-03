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
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int n, m, mn, mx;
    
    cin >> n >> m >> mn >> mx;
    
    bool is_mn = false;
    bool is_mx = false;
    
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        if (x < mn || x > mx) {
            cout << "Incorrect" << endl; 
            return 0;
        }
        if (x == mn) {
            is_mn = true;
        }
        if (x == mx) {
            is_mx = true;
        }
    }
    
    if (mn == mx) {
        cout << "Correct" << endl;
    } else {
        int d = !is_mn + !is_mx;
        if (m + d <= n) {
            cout << "Correct" << endl;
        } else {
            cout << "Incorrect" << endl;
        }
    }

    return 0;
}