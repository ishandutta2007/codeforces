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

const int IT_MAX = 524288;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

map <string, int> M;
char in[30];
void init() {
    for (int i = 0; in[i] != 0; i++) in[i] = 0;
}

vector <int> conn[502];
int Q[502];
int dis[502];
int main() {
    int N, i, j, t1, t2;
    string t = string("polycarp");
    M[t] = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%s", in);
        for (j = 0; in[j] != 0; j++) if (in[j] <= 'Z' && in[j] >= 'A') in[j] = in[j] - 'A' + 'a';   
        t = string(in);
        if (M.count(t) == 0) M[t] = M.size();
        t1 = M[t];
        init();

        scanf("%s", in);
        init();

        scanf("%s", in);
        for (j = 0; in[j] != 0; j++) if (in[j] <= 'Z' && in[j] >= 'A') in[j] = in[j] - 'A' + 'a';
        t = string(in);
        if (M.count(t) == 0) M[t] = M.size();
        t2 = M[t];
        init();

        conn[t2].push_back(t1);
    }
    
    int st = 1, en = 2;
    Q[0] = 0;
    dis[0] = 1;
    while (st < en) {
        t1 = Q[st];
        for (i = 0; i < conn[t1].size(); i++) {
            t2 = conn[t1][i];
            Q[en++] = t2;
            dis[t2] = dis[t1] + 1;
        }
        st++;
    }
    printf("%d", dis[Q[en - 1]]);
    return 0;
}
//*/