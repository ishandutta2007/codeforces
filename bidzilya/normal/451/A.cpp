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

    int n, m;
    cin >> n >> m;

    if (min(n, m) % 2 == 1) {
        cout << "Akshat" << endl;
    } else {
        cout << "Malvika" << endl;
    }

    return 0;
}