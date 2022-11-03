#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int max_n = 2e5 + 10;

int n, t, c;
int s[max_n];

inline int sum(int l, int r)
{
    if (l == 0)
        return s[r];
    else
        return s[r] - s[l - 1];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &t, &c);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x > t) {
            s[i] = 1;
        } else {
            s[i] = 0;
        }
    }
    
    for (int i = 1; i < n; ++i)
        s[i] += s[i - 1];
        
    int ans = 0;
    for (int i = 0; i + c - 1 < n; ++i)
        if (sum(i, i + c - 1) == 0) 
            ++ans;
    
    printf("%d\n", ans);
    
        

    return 0;
}