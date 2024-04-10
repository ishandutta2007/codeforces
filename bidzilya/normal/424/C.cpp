#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 1e6 + 10;

int n;
int ans;

int cx[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
        
    cx[0] = 0;
    for (int i = 1; i < max_n; ++i)
        cx[i] = (cx[i - 1] ^ i);
        
    scanf("%d", &n);
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        ans ^= p;
    }
    
    for (int i = 2; i <= n; ++i) {
        int k = n / i;
        if ((k & 1) == 1) ans ^= cx[i - 1];
        k = n - k * i;
        ans ^= cx[k];
    }
    
    printf("%d\n", ans);
    
    return 0;
}