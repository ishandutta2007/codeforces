#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 1e4;
int sum[N + 1];
int n;
char s[1000];
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        bool bz = (s[i] == '1');
        for (int j = 0; j <= N ; j++){
            if (j >= b && (j - b) % a == 0) bz ^= 1;
            sum[j] += bz;
        }
    }
    int ans = 0;
    for (int i = 0;i <= N ; i ++)
        ans= max(ans,sum[i]);
    printf("%d\n", ans);
    return 0;
}