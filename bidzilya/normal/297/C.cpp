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

pair<int, int> s[max_n];
int n;

int a[max_n];
int b[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i].first);
        s[i].second = i;
    }
    sort(s, s + n);
    int d = n / 3;
    if (d * 3 < n) ++d;
    for (int i = 0; i < d; ++i) {
        int id = s[i].second;
        a[id] = i;
        b[id] = s[i].first - i;
    }
    for (int i = d; i < n && i < 2 * d; ++i) {
        int id = s[i].second;
        b[id] = i;
        a[id] = s[i].first - i;
    }
    for (int i = 2 * d; i < n; ++i) {
        int id = s[i].second;
        b[id] = 3 * d - i - 1;
        a[id] = s[i].first - b[id];
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}