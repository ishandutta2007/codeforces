//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <unordered_map>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

char c[3];
int main(){
    int ans = 1;
    scanf("%s", c);
    if(c[0] == 'a' || c[0] == 'h') ans *= 2;
    else ans *= 3;

    if(c[1] == '1' || c[1] == '8') ans *= 2;
    else ans *= 3;
    ans--;
    return !printf("%d\n", ans);
}