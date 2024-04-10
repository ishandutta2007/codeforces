//*
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef set<int>::iterator siit;

int chk[1000050];
int main() {
    int i;
    ll H1, A1, X1, Y1, H2, A2, X2, Y2, M;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &M, &H1, &A1, &X1, &Y1, &H2, &A2, &X2, &Y2);

    ll C1, C2, F1, F2, st;
    for (i = 0; i < M; i++) chk[i] = -1;
    st = H1;
    chk[st] = 0;
    for (i = 1; i <= 2*M; i++) {
        st = (X1*st + Y1) % M;
        if (chk[st] != -1) {
            C1 = i - chk[st];
            if (chk[A1] < chk[st]) F1 = -1;
            else F1 = chk[A1];
            break;
        }
        chk[st] = i;
    }
    if (F1 == -1) {
        if (chk[A1] == -1) {
            printf("-1");
            return 0;
        }
        else {
            C1 = -1;
            F1 = chk[A1];
        }
    }

    for (i = 0; i < M; i++) chk[i] = -1;
    st = H2;
    chk[st] = 0;
    for (i = 1; i <= 2 * M; i++) {
        st = (X2*st + Y2) % M;
        if (chk[st] != -1) {
            C2 = i - chk[st];
            if (chk[A2] < chk[st]) F2 = -1;
            else F2 = chk[A2];
            break;
        }
        chk[st] = i;
    }

    if (F2 == -1) {
        if (chk[A2] == -1) {
            printf("-1");
            return 0;
        }
        else {
            C2 = -1;
            F2 = chk[A2];
        }
    }

    if (C1 == -1 && C2 == -1) {
        if (F1 == F2) printf("%lld", F1);
        else printf("-1");
        return 0;
    }

    if (C1 == -1) {
        if (F1 >= F2 && (F1 - F2) % C2 == 0) printf("%lld", F1);
        else printf("-1");
        return 0;
    }

    if (C2 == -1) {
        if (F2 >= F1 && (F2 - F1) % C1 == 0) printf("%lld", F2);
        else printf("-1");
        return 0;
    }
    if (F1 > F2) {
        swap(F1, F2);
        swap(C1, C2);
    }

    for (i = 0; i <= C1; i++) {
        ll t = F2 + C2 * i;
        if (t % C1 == F1 % C1) break;
    }

    if (i > C1) printf("-1");
    else printf("%lld", F2 + C2*i);
    return 0;
}
//*/