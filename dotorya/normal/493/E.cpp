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

int main() {
    ll T, A, B;
    scanf("%lld %lld %lld", &T, &A, &B);
    if(T > A || A > B) {
        if(A == B) printf("1");
        else printf("0");
        return 0;
    }
    if(T == A) {
        if(T == 1) {
            if(A != B) printf("0");
            else printf("inf");
        }
        else {
            if(A != B) printf("0");
            else printf("2");
        }
        return 0;
    }
    if(A == B) {
        printf("1");
        return 0;
    }

    ll t1 = B, t2 = 1, t3 = 0, t4;
    int i, j;
    for(i = 0; t1 != 0; i++) {
        t4 = t1%A;
        t3 += t4 * t2;
        t1 /= A;
        t2 *= T;
    }
    if(t3 == A) {
        printf("1");
        return 0;
    }
    if(T == 1) {
        while(B%A == 0) B /= A;
        if(B == 1) printf("1");
        else printf("0");
        return 0;
    }
    printf("0");
    return 0;
}

//*/