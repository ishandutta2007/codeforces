//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;

vector <int> D[4];
int main() {
    int N, i, t;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        D[t].push_back(i);
    }
    printf("%d\n", min(D[1].size(), min(D[2].size(), D[3].size())));
    for(i = 0; i < D[1].size() && i < D[2].size() && i < D[3].size(); i++) {
        printf("%d %d %d\n", D[1][i], D[2][i], D[3][i]);
    }
    return 0;
}

//*/