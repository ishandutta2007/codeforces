#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 201000;

struct node {
    long long A, B;
    bool operator < (const node &C) const {
        return B < C.B;
    }
};

long long C[MAXN], D[MAXN];

node AB[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    long long N;
    int M, K;
    long long x, s;
    
    cin >> N >> M >> K;
    cin >> x >> s;
    
    for (int i = 0; i < M; ++i) cin >> AB[i].A;
    for (int i = 0; i < M; ++i) cin >> AB[i].B;
    
    sort(AB, AB + M);
    
    multiset<long long> S;
    for (int i = 0; i < M; ++i) S.insert(AB[i].A);
    
    for (int i = 0; i < K; ++i) cin >> C[i];
    for (int i = 0; i < K; ++i) cin >> D[i];
    
    long long ans = x * N;
    int j = M - 1;
    
    while (j >= 0 && AB[j].B > s) {
        S.erase(S.find(AB[j].A));
        --j;
    }
    if (!S.empty()) ans = min(ans, (*S.begin()) * N);
    
    
    for (int i = 0; i < K; ++i) {
        if (s < D[i]) break;
        long long res = s - D[i];
        long long rem = N - C[i];
        while (j >= 0 && AB[j].B > res) {
            S.erase(S.find(AB[j].A));
            --j;
        }
        long long T = x;
        if (!S.empty()) T = min(*S.begin(), T);
      //  cout << i << " " << T << " " << res << " " << rem<< endl;
        if (rem < 0) ans = 0; else ans = min(ans, T * rem);
    }
    
    
    cout << ans << endl;

    return 0;
}