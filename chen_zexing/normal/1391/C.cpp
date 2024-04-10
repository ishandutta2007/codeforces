#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
char s[105][105];
int main() {
    int n;
    cin >> n;
    long long ans = 1;
    long long minus=1;
    for (int i = 1; i <= n; i++)
        ans = ans * i % 1000000007;
    for(int i=1;i<n;i++)
        minus=minus*2%1000000007;
    ans -= minus;
    ans += 1000000007;
    ans %= 1000000007;
    printf("%lld\n", ans);
    return 0;
}