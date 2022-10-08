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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

char in1[100050];
char in2[100050];
char in3[100050];
int cnt1[26];
int cnt2[26];
int cnt3[26];
int main() {
    int L1, L2, L3, i, j, ans = 0, ans1 = 0, ans2 = 0;
    scanf("%s %s %s", in1, in2, in3);
    for (L1 = 0; in1[L1] != 0; L1++) cnt1[in1[L1] - 'a']++;
    for (L2 = 0; in2[L2] != 0; L2++) cnt2[in2[L2] - 'a']++;
    for (L3 = 0; in3[L3] != 0; L3++) cnt3[in3[L3] - 'a']++;

    for (i = 0;; i++) {
        int tmp = INF;
        for (j = 0; j < 26; j++) {
            if (cnt3[j] == 0) continue;
            tmp = min(tmp, cnt1[j] / cnt3[j]);
        }

        if (ans < i + tmp) {
            ans = i + tmp;
            ans1 = i;
            ans2 = tmp;
        }
        for (j = 0; j < 26; j++) {
            cnt1[j] -= cnt2[j];
            if (cnt1[j] < 0) break;
        }
        if (j < 26) break;
    }
    
    for (i = 0; i < 26; i++) cnt1[i] = 0;
    for (L1 = 0; in1[L1] != 0; L1++) cnt1[in1[L1] - 'a']++;
    for (i = 0; i < 26; i++) cnt1[i] -= ans1*cnt2[i] + ans2*cnt3[i];

    for (i = 1; i <= ans1; i++) printf("%s", in2);
    for (i = 1; i <= ans2; i++) printf("%s", in3);
    for (i = 0; i < 26; i++) for (j = 1; j <= cnt1[i]; j++) printf("%c", 'a' + i);
    return 0;
}
//*/