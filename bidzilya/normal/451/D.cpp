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

const int max_n = 1e5 + 10;

int n;
char s[max_n];

ll d[2][2];

ll a0, a1;

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%s", s);
    n = strlen(s);
    
    a0 = a1 = 0;
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            d[i][j] = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        ++d[i & 1][s[i] - 'a'];
        a0 += d[(i & 1) ^ 1][s[i] - 'a'];
        a1 += d[i & 1][s[i] - 'a'];
    }
    
    cout << a0 << " " << a1 << endl;
    


    return 0;
}