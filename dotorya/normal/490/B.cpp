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

int in[1000050];
int conn[1000050];
vector <int> ANS1;
vector <int> ANS2;
int main() {
    int N, i, t1, t2, st;
    scanf("%d", &N);
    for(i = 1; i <= 1000000; i++) conn[i] = -1;
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &t1, &t2);
        if(t1 != 0) {
            conn[t1] = t2;
            in[t2]++;
        }
        if(t1 == 0) st = t2;
    }

    for(i = 1; i <= 1000000; i++) if(conn[i] != -1 && in[i] == 0 && st != i) break;

    for(;i>0;) {
        ANS1.push_back(i);
        i = conn[i];
    }
    for(i = st; i > 0; ) {
        ANS2.push_back(i);
        i = conn[i];
    }

    for(i = 0; i < ANS2.size(); i++) printf("%d %d ", ANS1[i], ANS2[i]);
    if(N%2==1) printf("%d", ANS1.back());
    return 0;
}