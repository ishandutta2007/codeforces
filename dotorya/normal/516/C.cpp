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

const int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

ll D[100050];
ll H[100050];
ll S[2][IT_MAX*2];
int IT[2][IT_MAX*2+50];
void update(int chk, int node) {
    IT[chk][node] = node-IT_MAX+1;
    while(node > 1) {
        node /= 2;
        if(S[chk][IT[chk][node*2]] > S[chk][IT[chk][node*2+1]]) IT[chk][node] = IT[chk][node*2];
        else IT[chk][node] = IT[chk][node*2+1];
    }
    return;
}
int get_MAX(int chk, int pos1, int pos2) {
    int t = -1;
    if(pos1 == pos2) return IT[chk][pos1];
    if(pos1 % 2 == 1) {
        t = IT[chk][pos1];
        pos1++;
    }
    if(pos1 == pos2) {
        if(t != -1 && S[chk][t] > S[chk][IT[chk][pos1]]) return t;
        else return IT[chk][pos1];
    }
    if(pos2 % 2 == 0) {
        if(S[chk][t] < S[chk][IT[chk][pos2]]) t = IT[chk][pos2];
        pos2--;
    }
    int t2 = get_MAX(chk, pos1/2, pos2/2);
    if(t != -1 && S[chk][t] > S[chk][t2]) return t;
    else return t2;
}

int main() {
    int N, M, i, j, t1, t2, st, en, mx1, mx2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%d", &D[i]);
    for(i = 1; i <= N; i++) scanf("%d", &H[i]);

    // Update IT
    for(i = 0; i <= 2*IT_MAX; i++) S[0][i] = S[1][i] = -LL_INF;
    
    ll D_SUM = 0;
    for(i = 1; i <= 2*N; i++) {
        S[0][i] = D_SUM+2*H[(i-1)%N+1];
        S[1][i] = 2*H[(i-1)%N+1]-D_SUM;
        update(0, IT_MAX+i-1);
        update(1, IT_MAX+i-1);
        D_SUM += D[(i-1)%N+1];
    }

    // Get ANS
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        if(t1 > t2) {st = t2+1; en = t1-1;}
        else {st = t2+1; en = t1+N-1;}
        mx1 = get_MAX(0, st+IT_MAX-1, en+IT_MAX-1);
        mx2 = get_MAX(1, st+IT_MAX-1, en+IT_MAX-1);
        if(mx1 != mx2) {
            printf("%lld\n", S[0][mx1]+S[1][mx2]);
            continue;
        }
        int t3 = -1, t4 = -1;
        ll ANS = -LL_INF;
        if(mx1 != st) {
            t3 = get_MAX(1, st+IT_MAX-1, mx1+IT_MAX-2);
            ANS = max(ANS, S[1][t3] + S[0][mx2]);
        }
        if(mx1 != en) {
            t3 = get_MAX(0, mx1+IT_MAX, en+IT_MAX-1);
            ANS = max(ANS, S[0][t3] + S[1][mx1]);
        }
        printf("%lld\n", ANS);
        continue;
    }
    return 0;
}

//*/