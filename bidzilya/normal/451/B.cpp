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

int a[max_n];
int n;

bool good()
{
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);


    if (good()) {
        printf("yes\n");
        printf("1 1\n");
        return 0;
    }

    int l, r;

    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i]) {
            l = i - 1;
            r = l + 1;
            while (r + 1 < n && a[r] > a[r + 1]) ++r;
            reverse(a + l, a + r + 1);
            break;
        }
        
    if (!good()) {
        printf("no\n");
    } else {
        printf("yes\n");
        printf("%d %d\n", l + 1, r + 1);
    }


    return 0;
}