#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 1e3 + 10;

int n;
int s;
int x[max_n], y[max_n], k[max_n];

int check(double r)
{
    int S = s;
    for (int i = 0; i < n; ++i)
        if (x[i] * x[i] + y[i] * y[i] <= r * r) 
            S += k[i];
    return S;
}

int main()
{
//    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
 
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", x + i, y + i, k + i);
        
    bool found = 0;
    double lr = 0, rr = 1e5, ar;
    
    for (int itr = 0; itr < 200; ++itr) {
        double mr = (lr + rr) / 2.0;
        
        if (check(mr) >= 1000000) {
            found = 1;
            ar = mr;
            rr = mr;
        } else {
            lr = mr;
        }
    }
    if (!found) {
        printf("-1\n");
    } else {
        printf("%.15lf\n", ar);
    }
    
    return 0;
}