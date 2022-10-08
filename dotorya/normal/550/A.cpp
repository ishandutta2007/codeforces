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

char in[100050];
vector <int> pos1;
vector <int> pos2;
int main() {
    scanf("%s", in);
    int i, j;
    for (i = 0; in[i + 1] != 0; i++) {
        if (in[i] == 'A' && in[i + 1] == 'B') pos1.push_back(i);
        if (in[i] == 'B' && in[i + 1] == 'A') pos2.push_back(i);
    }

    for (i = 0; i < pos1.size(); i++) {
        for (j = 0; j < pos2.size(); j++) {
            if (abs(pos1[i] - pos2[j]) >= 2) break;
        }
        if (j < pos2.size()) break;
    }
    if (i < pos1.size()) printf("YES");
    else printf("NO");
    return 0;
}
//*/