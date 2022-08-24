#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
#define D long double
using namespace std;
D ans[65][2][2][2][2][2][2];
int32_t main(){
    int n;
    cin >> n;
    int number = (1 << n);
    int matrix[number][number];
    for (int i=0; i < number; i++){
        for (int j=0; j < number; j++){
            cin >> matrix[i][j];
        }
    }
    D dp[n+1][number];
    for (int i=0; i <= n; i++){
        for (int j=0; j < number; j++){
            dp[i][j] = 0;
        }
    }
    for (int i=0; i < number; i++){
        dp[0][i] = 1;
    }
    for (int i=1; i <= n; i++){
        int blocks = (1 << (i-1));
        bool nb = true;
        for (int start=0; start < number; start += blocks){
            for (int team=start; team < start+blocks;team++){
                if (nb){
                    for (int vs=start+blocks; vs< start+2*blocks; vs++){
                        D ver1 = dp[i-1][team] * dp[i-1][vs] * (D) matrix[team][vs] / (D) 100;
                        dp[i][team] += ver1;
                    }
                }
                else{
                    for (int vs=start-blocks; vs< start; vs++){
                        D ver1 = dp[i-1][team] * dp[i-1][vs] * (D) matrix[team][vs] / (D) 100;
                        dp[i][team] += ver1;
                    }
                }
            }
            nb ^= 1;
        }
    }
    D ans[n+1][number];
    for (int i=0; i <= n; i++){
        for (int j=0; j < number; j++){
            ans[i][j] = 0;
        }
    }
    for (int i=1; i <= n; i++){
        int blocks = (1 << (i-1));
        bool nb = true;
        for (int start=0; start < number; start += blocks){
            for (int team=start; team < start+blocks;team++){
                D aa = 0;
                if (nb){
                    for (int vs=start+blocks; vs< start+2*blocks; vs++){
                        aa = max(aa, dp[i][team] * (D) blocks + ans[i-1][vs] + ans[i-1][team]);
                    }
                }
                else{
                    for (int vs=start-blocks; vs< start; vs++){
                        aa = max(aa, dp[i][team] * (D) blocks + ans[i-1][vs] + ans[i-1][team]);
                    }
                }
                ans[i][team] = aa;
            }
            nb ^= 1;
        }
    }
    D answer = 0;
    cout.precision(30);
    for (int i=0; i < number; i++){
        answer = max(answer, ans[n][i]);
    }
    cout << answer << endl;
    return 0;
}