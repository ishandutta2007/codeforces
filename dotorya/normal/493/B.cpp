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

vector <int> D1;
vector <int> D2;
void WIN(int x) {
    if(x == 1) printf("first");
    else printf("second");
    return;
}
int main() {
    int N, i, t;
    ll d1_sum = 0, d2_sum = 0, last;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        if(t > 0) {
            D1.push_back(t);
            last = 1;
            d1_sum += t;
        }
        else {
            D2.push_back(-t);
            last = 2;
            d2_sum -= t;
        }
    }

    if(d1_sum != d2_sum) {
        if(d1_sum < d2_sum) WIN(2);
        else WIN(1);
        return 0;
    }

    for(i = 0; i < D1.size() && i < D2.size(); i++) {
        if(D1[i] != D2[i]) break;
    }
    if(i < D1.size() && i < D2.size()) {
        if(D1[i] < D2[i]) WIN(2);
        else WIN(1);
        return 0;
    }
    if(D1.size() != D2.size()) {
        if(D1.size() < D2.size()) WIN(2);
        else WIN(1);
        return 0;
    }
    WIN(last);
    return 0;
}

//*/