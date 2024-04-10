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

const int modulo = 1e9 + 7;

inline int bit(int mask, int i)
{
    return (mask >> i) & 1;
}

const int max_bit = 20;
const int max_a = (1 << max_bit);

int n;
int a[max_a];

int pw2[max_a];
int t[max_a];

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    
    pw2[0] = 1;
    for (int i = 1; i < max_a; ++i) {
        pw2[i] = pw2[i - 1] * 2;
        if (pw2[i] >= modulo) pw2[i] -= modulo;
    }
    
    for (int i = 0; i < max_a; ++i)
        t[i] = a[i];
        
    for (int b = 0; b < max_bit; ++b)
        for (int i = 0; i < max_a; ++i)
            if (bit(i, b) == 0)
                t[i] += t[i + (1 << b)];

    int ans = 0;
    for (int mask = 0; mask < max_a; ++mask) {
        int bits = 0;
        for (int i = 0; i < 20; ++i)
            bits += bit(mask, i);
        if ((bits & 1) == 1) {
            ans -= pw2[t[mask]];
            if (ans < 0) ans += modulo;
        } else {
            ans += pw2[t[mask]];
            if (ans >= modulo) ans -= modulo;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}