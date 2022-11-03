#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
  
typedef long long ll;

const int max_n = 200;
const int max_m = max_n * (max_n - 1) / 2;
const int inf = 1e9;

int n, m;

int d[max_n][max_n];

int A[max_m];
int B[max_m];
int C[max_m];

int ans_d;

multiset<int> q1, q2;

pair<int, int> p[max_n];
int psz;

inline void update_ans(int val)
{
    if (ans_d == -1 || val < ans_d) {
        ans_d = val;
    }
}

inline void update1(int L, int R, int x)
{
    update_ans(x + L);
}

inline void update2(int L, int R, int x)
{
    update_ans(x - R);
}

void solve(int L, int R)
{
    if (q1.empty()) {
        update2(L, R, (*q2.rbegin()));
    } else if (q2.empty()) {
        update1(L, R, (*q1.rbegin()));
    } else {
        int x1 = (*q1.rbegin());
        int x2 = (*q2.rbegin());
        
        int T = (x2 - x1) / 2;
        if (T < L) {
            update1(L, R, x1);
        } else if (T > R) {
            update2(L, R, x2);
        } else {
            update2(L, T, x2);
            update1(T, R, x1);
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
    
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        --A[i]; --B[i]; C[i] *= 4;
        d[A[i]][B[i]] = d[B[i]][A[i]] = C[i];
    }
    
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    ans_d = -1;
    
    for (int edge = 0; edge < m; ++edge) {
        q1.clear();
        q2.clear();
        psz = 0;
        int vA = A[edge];
        int vB = B[edge];
        int cost = C[edge];
        for (int i = 0; i < n; ++i)
            if (d[vA][i] + cost == d[vB][i]) {
                q1.insert(d[vA][i]);
            } else if (d[vB][i] + cost == d[vA][i]) {
                q2.insert(d[vB][i] + cost);
            } else {
                int T = (d[vB][i] + cost - d[vA][i]) / 2;
                if (T < 0) {
                    q2.insert(d[vB][i] + cost);
                } else if (T > cost) {
                    q1.insert(d[vA][i]);
                } else {
                    q1.insert(d[vA][i]);
                    p[psz].first = T;
                    p[psz].second = i;
                    ++psz;
                }
            }
        if (psz == 0) {
            solve(0, cost);
        } else {
            sort(p, p + psz);
            solve(0, p[0].first);
            for (int i = 0; i < psz; ++i) {
                if (i != 0) {
                    solve(p[i - 1].first, p[i].first);
                }
                int v = p[i].second;
                q1.erase(q1.find(d[vA][v]));
                q2.insert(d[vB][v] + cost);
            }
            solve(p[psz - 1].first, cost);
        }
    }

    printf("%.9lf\n", ans_d / 4.0);
    
    return 0;
}