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

const int max_n = 100;

int a[max_n];  
int b[max_n];
int n;

int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    int a_sz, b_sz;
    scanf("%d%d", &a_sz, &b_sz);
    for (int i = 0; i < a_sz; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        a[x] = 1;
    }
    for (int i = 0; i < b_sz; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        b[x] = 1;
    }
    for (int i = 0; i < n; ++i)
        if (a[i]) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    printf("\n");
    return 0;
}