#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int max_n = 5e3;

string s1, s2;

int e12[max_n][max_n];
int e11[max_n][max_n];
int e22[max_n][max_n];

int e1[max_n];
int e2[max_n];
int e[max_n];

void find_dp(const string& s1, const string& s2, int dp[max_n][max_n])
{
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = 0; i < l2; ++i)
        dp[l1 - 1][i] = (s1[l1 - 1] == s2[i]);
        
    for (int i = l1 - 2; i >= 0; --i) {
        dp[i][l2 - 1] = (s1[i] == s2[l2 - 1]);
        for (int j = l2 - 2; j >= 0; --j)
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = 0;
            }
    }
}

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    cin >> s1;
    cin >> s2;
    
    find_dp(s1, s1, e11);
    find_dp(s1, s2, e12);
    find_dp(s2, s2, e22);

    int l1 = s1.length();
    int l2 = s2.length();
    
    for (int i = 0; i < l1; ++i) {
        e1[i] = 0;
        for (int j = 0; j < l1; ++j)
            if (i != j)
                e1[i] = max(e1[i], e11[i][j]);
    }
    
    for (int i = 0; i < l2; ++i) {
        e2[i] = 0;
        for (int j = 0; j < l2; ++j)
            if (i != j)
                e2[i] = max(e2[i], e22[i][j]);
    }
    
    int ans = -1;
    for (int i = 0; i < l1; ++i) {
        int ml1 = e1[i] + 1;
        if (i + ml1 - 1 < l1) {
            for (int j = 0; j < l2; ++j) {
                int ml2 = e2[j] + 1;
                if (j + ml2 - 1 < l2) {
                    int ml = max(ml1, ml2);
                    if (ml <= e12[i][j]) {
                        if (ans == -1 || ml < ans) {
                            ans = ml;
                        }
                    }
                }
            }
        }
    }
            

    cout << ans << endl;
            
    
    
    return 0;
}