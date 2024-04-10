#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <bitset>
#include <fstream>
#define int long long
using namespace std;
int INF = 1000000000000000001;
int dp[9][11][100][11];
int solve(int st, int number){
    if (number == 0) return 0;
    vector<int> symb;
    while (number > 0){
        symb.push_back(number % st);
        number /= st;
    }
    vector<int> real;
    for (int i=symb.size() - 1; i >= 0; i--){
        real.push_back(symb[i]);
    }
    int ans = 0;
    for (int sz=2; sz < real.size(); sz += 2){
        ans += (st-1) * dp[st-2][1][sz-1][0];
    }
    if (real.size() % 2 != 0) return ans;
    bool b[st];
    for (int i=0; i < st; i++){
        b[i] = false;
    }
    int vv = 0;
    for (int i=0; i < real.size(); i++){
        int stx = 0;
        if (i == 0) stx = 1;
        int ost = real.size() - i - 1;
        for (int j=stx; j < real[i]; j++){
            int vvv = vv;
            if (b[j]) vvv--;
            else vvv++;
            ans += dp[st-2][vvv][ost][0];
        }
        if (b[real[i]]) vv--;
        else vv++;
        b[real[i]] ^= 1;
    }
    return ans + (vv == 0);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i < 9; i++){
        for (int j=0; j <= 10; j++){
            for (int k=0; k < 100; k++){
                for (int l=0; l <= 10; l++){
                    dp[i][j][k][l] = 0;
                }
            }
            if (j <= i + 2){
                dp[i][j][0][j] = 1;
            }
        }
    }
    for (int i=0; i < 9; i++){
        for (int j=0; j <= 10; j++){
            for (int k=1; k < 100; k++){
                for (int l=0; l <= 10; l++){
                    if (j > i + 2 || l > i + 2) continue;
                    if (l-1 >= 0){
                        dp[i][j][k][l] += dp[i][j][k-1][l-1] * (i - l + 3);
                        dp[i][j][k][l] %= INF;
                    }
                    if (l + 1 <= i + 2){
                        dp[i][j][k][l] += dp[i][j][k-1][l+1] * (l + 1);
                        dp[i][j][k][l] %= INF;
                    }
                }
            }
        }
    }
    for (int i=0; i < n; i++){
        int b, l, r;
        cin >> b >> l >> r;
        int x = solve(b, r) - solve(b, l-1);
        cout << x << endl;
    }
    return 0;
}