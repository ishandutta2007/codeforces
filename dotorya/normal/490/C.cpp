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

char d[1000050];
ll remA[1000050];
ll remB[1000050];
ll pow10[1000050];
int main() {
    int A, B, i, j, L;
    scanf("%s", d);
    for(L = 0; d[L] != 0; L++);
    scanf("%d %d", &A, &B);

    pow10[0] = 1%B;
    remA[0] = (d[0]-'0')%A;
    for(i = 1; i < L; i++) pow10[i] = (pow10[i-1]*10)%B;
    for(i = 1; i < L; i++) remA[i] = (remA[i-1]*10+d[i]-'0')%A;
    
    remB[L-1] = (d[L-1]-'0')%B;
    for(i = L-2; i >= 0; i--) remB[i] = (remB[i+1]+(d[i]-'0')*pow10[L-1-i])%B;

    for(i = 0; i < L-1; i++) {
        if(remA[i] == 0 && remB[i+1] == 0 && d[i+1] != '0') break;
    }

    if(i == L-1) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(j = 0; j <= i; j++) printf("%c", d[j]);
    printf("\n");
    for(j = i+1; j < L; j++) printf("%c", d[j]);

    return 0;
}

//*/