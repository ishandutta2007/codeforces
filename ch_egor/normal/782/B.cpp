#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int v[228228];
int x[228228];

double get(double xx)
{
    double ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, fabs(xx - x[i]) / v[i]);
    return ans;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    
    double l = -1;
    double r = 1e9 + 228;
    for (int i = 0; i < 200; ++i)
    {
        double x1 = (2 * l + r) / 3;
        double x2 = (l + 2 * r) / 3;
        if (get(x1) > get(x2))
            l = x1;
        else
            r = x2;
    }
    
    printf("%.9lf\n", get(l));
    
	return 0;
}