#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <functional>
#include <iterator>

#define MX 500005
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

typedef long long LL;

map <LL, int> H;

int N;
int a[MX];
LL sum[MX], S[MX];
int tot[MX];

int main() {
    
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    cin >> N;
    rep(i, N) scanf("%d", a + i);
    if (N < 3) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = N - 1; i >= 0; i --) {
        sum[i] = a[i];  
        if (i < N - 1) sum[i] += sum[i + 1];
        S[i] = sum[i];
    }
    
    sort(S, S + N);
    int n = unique(S, S + N) - S;
    int id;
    LL s(0LL);
    LL rlt(0LL);
    
    rep(i, N) {
        id = lower_bound(S, S + n, sum[i]) - S;
        tot[id] ++; 
    }
    
    for (int i = 0; i < N - 2; i ++) {
        s += a[i];
        id = lower_bound(S, S + n, sum[i]) - S;
        tot[id] --;
        if (sum[i + 1] != s * 2) continue;
        if (s != 0LL) {
            id = lower_bound(S, S + n, s) - S;
            if (id < n && S[id] == s) rlt += tot[id];
            continue;
        }
        id = lower_bound(S, S + n, s) - S;
        rlt += tot[id] - 1;
    }
    cout << rlt << endl;
    return 0;
}