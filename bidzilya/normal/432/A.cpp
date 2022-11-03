#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    int n, k;
    int c = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (5 - x >= k) ++c;
    }
    printf("%d\n", c / 3);
    
    return 0;
}