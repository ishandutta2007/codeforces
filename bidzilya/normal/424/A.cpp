#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d\n", &n);
    
    int c1, c2;
    c1 = c2 = 0;
    
    char s[222];
    scanf("%s\n", s);
    for (int i = 0; i < n; ++i)
        if (s[i] == 'X') ++c1;
            else ++c2;

    int ans = 0;
    
    for (int i = 0; i < n; ++i)
        if (s[i] == 'X' && c1 > c2) {
            s[i] = 'x';
            --c1; ++c2;
            ++ans;
        } else if (s[i] == 'x' && c1 < c2) {
            s[i] = 'X';
            ++c1; --c2;
            ++ans;
        }
    printf("%d\n", ans);
    printf("%s\n", s);
    
    return 0;
}