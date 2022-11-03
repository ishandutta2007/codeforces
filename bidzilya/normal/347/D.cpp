#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 1e2 + 10;
const int max_c = 26;

struct Pred {
    int i, j, k;
    
    Pred():
        i(0),
        j(0),
        k(0)
    {}
    
    Pred(int _i, int _j, int _k):
        i(_i),
        j(_j),
        k(_k)
    {}
};

int dp[max_n][max_n][max_n];
Pred pr[max_n][max_n][max_n];
int eq[max_n][max_c];
int n1, n2, n3;
string s1, s2, s3;

void print_answer(const Pred& p) {
    if (p.i == 0 || p.j == 0) 
        return;
    Pred pp(pr[p.i][p.j][p.k]);
    print_answer(pp);
    if (dp[pp.i][pp.j][pp.k] != dp[p.i][p.j][p.k]) 
        cout << s1[p.i - 1];
}

void build_eq() {
    for (int k = 0; k < n3; ++k) 
        for (int ci = 0; ci < max_c; ++ci) {
            char c = (char)(ci + 'A');
            for (int j = k; j >= 0; --j)
                if (s3[j] == c) {
                    bool may = true;
                    for (int t = 0; t < j; ++t)
                        if (s3[t] != s3[t + k - j]) {
                            may = false;
                            break;
                        }
                    if (may) {
                        eq[k][ci] = j + 1;
                        break;
                    }
                }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3;
    n1 = s1.length();
    n2 = s2.length();
    n3 = s3.length();
    build_eq();
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n2; ++j)    
            for (int k = 0; k < n3; ++k) {
                if (dp[i + 1][j][k] < dp[i][j][k]) {
                    dp[i + 1][j][k] = dp[i][j][k];
                    pr[i + 1][j][k].i = i;
                    pr[i + 1][j][k].j = j;
                    pr[i + 1][j][k].k = k;
                } 
                if (dp[i][j + 1][k] < dp[i][j][k]) {
                    dp[i][j + 1][k] = dp[i][j][k];
                    pr[i][j + 1][k].i = i;
                    pr[i][j + 1][k].j = j;
                    pr[i][j + 1][k].k = k;
                }
                if (s1[i] == s2[j]) {
                    int k1 = eq[k][s1[i] - 'A'];
                    if (dp[i + 1][j + 1][k1] < dp[i][j][k] + 1) {
                        dp[i + 1][j + 1][k1] = dp[i][j][k] + 1;
                        pr[i + 1][j + 1][k1].i = i;
                        pr[i + 1][j + 1][k1].j = j;
                        pr[i + 1][j + 1][k1].k = k;
                    }
                }
            }
    int ans_length = 0;
    for (int i = 0; i <= n1; ++i)
        for (int j = 0; j <= n2; ++j)
            for (int k = 0; k < n3; ++k)
                ans_length = max(ans_length, dp[i][j][k]);
    if (ans_length == 0) {
        cout << 0 << endl;
        return 0;
    }
        for (int i = 0; i <= n1; ++i)
            for (int j = 0; j <= n2; ++j)
                for (int k = 0; k < n3; ++k)
                    if (ans_length == dp[i][j][k]) {
                        print_answer(Pred(i, j, k));
                        return 0;
                    }
}