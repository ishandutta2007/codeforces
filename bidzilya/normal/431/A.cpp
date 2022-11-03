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
using namespace std;
  
typedef long long ll;

int a[4];
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    for (int i = 0; i < 4; ++i) cin >> a[i];
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        sum += a[s[i] - '1'];
    }
    cout << sum << endl;

    return 0;
}