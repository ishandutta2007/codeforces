#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1011111111;

int k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &k);
    for (char c = 'a'; c <= 'z'; ++c) {
        printf("%c", c);
        for (int i = 1; k >= i; ++i) {
            k -= i;
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}