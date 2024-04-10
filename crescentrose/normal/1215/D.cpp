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
int n;
int sum[2], v[2];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++){
        char c;
        scanf(" %c", &c);
        if (c == '?')
            sum[i > n / 2] ++;
        else
            v[i > n / 2] += c - '0';
    }
    if (!sum[0] && ! sum[1]){
        if (v[0] == v[1]){
            printf("Bicarp");
        }else
            printf("Monocarp");
        return 0;
    }
    int sum0 = sum[0], sum1 = sum[1], v0 = v[0],v1 = v[1];
    while (sum0||sum1) {
        if (sum1)
            sum1--, v1 += 9;
        else
            sum0--;
        if (sum0)
            sum0--, v0 += 9;
        else
            sum1--;
    }
    if (v0 < v1){
        printf("Monocarp");
        return 0;
    }
    sum0 = sum[1], sum1 = sum[0], v0 = v[1],v1 = v[0];
    while (sum0||sum1) {
        if (sum1)
            sum1--, v1 += 9;
        else
            sum0--;
        if (sum0)
            sum0--, v0 += 9;
        else
            sum1--;
    }
    if (v0 < v1){
        printf("Monocarp");
        return 0;
    }
    printf("Bicarp");
    return 0;
}