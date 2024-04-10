//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

char S[100050];
char T[100050];
vector <int> DIFF;
int main() {
    scanf("%s %s", &S, &T);
    for (int i = 0; S[i] != 0; i++) {
        if (S[i] != T[i]) DIFF.push_back(i);
    }
    if (DIFF.size() % 2 == 1) printf("impossible");
    else {
        for (int i = 0; i < DIFF.size() / 2; i++) S[DIFF[i]] = '0' + '1' - S[DIFF[i]];
        printf("%s", S);
    }
    return 0;
}
//*/