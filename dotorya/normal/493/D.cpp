//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
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


int main() {
    int N;
    scanf("%d", &N);

    if(N % 2 == 1) printf("black");
    else printf("white\n1 2");
    return 0;
}

//*/