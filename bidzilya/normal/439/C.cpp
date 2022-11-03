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
 
const int max_n = 1e5;
 
int n, k, p;

vector<int> a[2];
vector<vector<int> > d;
    
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    k -= p;
    
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[x % 2].push_back(x);
    }
    
    int s1 = a[1].size();
    int s0 = a[0].size();
    
    if (((k % 2) == (s1 % 2)) && (k <= s1) && ((s1 - k) / 2 + s0 >= p)) {
        d.resize(n);
        int p1 = 0, p0 = 0;
        for (int i = 0; i < k; ++i) {
            d[i].push_back(a[1][p1]);
            ++p1;
        }
        for (int i = 0; i < p; ++i) {
            if (p0 < s0) {
                d[k + i].push_back(a[0][p0]);
                ++p0;
            } else {
                d[k + i].push_back(a[1][p1]);
                d[k + i].push_back(a[1][p1 + 1]);
                p1 += 2;
            }
        }
        while (p1 < s1) {
            d[0].push_back(a[1][p1]);
            d[0].push_back(a[1][p1 + 1]);
            p1 += 2;
        }
        while (p0 < s0) {
            d[0].push_back(a[0][p0]);
            ++p0;
        }
        printf("YES\n");
        for (int i = 0; i < k + p; ++i) {
            printf("%d ", (int) d[i].size());
            for (int j = 0; j < (int) d[i].size(); ++j)
                printf("%d ", d[i][j]);
            printf("\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}