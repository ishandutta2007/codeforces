#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int n, h[max_n], g[max_n];
int ch[max_n], cg[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &ch[i], &cg[i]);
        ++h[ch[i]];
        ++g[cg[i]];
    }
    
    for (int i = 0; i < n; ++i) {
        int ag, ah;
        ah = n - 1 + h[cg[i]];
        ag = n - 1 - h[cg[i]];
        printf("%d %d\n", ah, ag);
    }
    
    return 0;
}