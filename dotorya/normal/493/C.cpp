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
const int INF = 1234567891;
vector <int> D1;
vector <int> D2;
int binary_cnt(int x) {
    int st = 0, en = D2.size()-1, mi, ans = D2.size();
    while(st <= en) {
        mi = (st+en)/2;
        if(D2[mi] >= x) {
            ans = mi;
            en = mi-1;
        }
        else st = mi+1;
    }
    return D2.size()-ans;
}
int main() {
    int N1, N2, i, t, t1, t2;
    scanf("%d", &N1);
    for(i = 1; i <= N1; i++) {
        scanf("%d", &t);
        D1.push_back(t);
    }
    scanf("%d", &N2);
    for(i = 1; i <= N2; i++) {
        scanf("%d", &t);
        D2.push_back(t);
    }
    sort(D1.begin(), D1.end());
    sort(D2.begin(), D2.end());

    int MAX = D1.size()*2-D2.size()*2;
    int MAX_chk = D1.size();
    for(i = D1.size()-1; i >= 0; i--) {
        t1 = 2*D1.size()+D1.size()-i;
        t2 = 2*D2.size()+binary_cnt(D1[i]);
        if(t1-t2 >= MAX) {
            MAX = t1-t2;
            MAX_chk = i;
        }
    }

    if(MAX_chk == D1.size()) {
        printf("%d:%d", D1.size()*2, D2.size()*2);
    }
    else {
        printf("%d:%d", D1.size()*2+D1.size()-MAX_chk, D2.size()*2+binary_cnt(D1[MAX_chk]));
    }

    return 0;
}

//*/