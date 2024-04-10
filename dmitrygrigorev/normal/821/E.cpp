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
#define int long long
using namespace std;
int K = 1000000007;
int dp[16][62][16][16];
int n, k, a, b, c;
vector<int> step;
vector<vector<int> > can;
vector<vector<int> > data;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> help1; help1.push_back(0); can.push_back(help1);
    for (int i=0;i<n;i++){
        cin >> a >> b >> c;
        if (i == n-1) b = k;
        vector<int> help; help.push_back(a); help.push_back(b); help.push_back(c);
        data.push_back(help);
    }
    for (int i=0;i<n-1;i++){
        vector<int> help;
        for (int j=0;j<=min(data[i][2], data[i+1][2]);j++){
            help.push_back(j);
        }
        can.push_back(help);
    }
    can.push_back(help1);
    int st = 1;
    for (int i=0;i<62;i++){
        step.push_back(st);
        st *= 2;
    }
    for (int i=0;i<16;i++){
        for (int j=0;j<62;j++){
            for (int l=0;l<16;l++){
                for (int p=0;p<16;p++){
                    dp[i][j][l][p] = 0;
                 }
            }
        }
    }
    for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            for (int p=0;p<16;p++){
                if (abs(j - p) <= 1 && j <= i && p <= i) dp[i][0][j][p] = 1;
            }
        }
        for (int j=1;j<62;j++){
            for (int l=0;l<16;l++){
                for (int p=0;p<16;p++){
                    for (int s=0;s<16;s++){
                        dp[i][j][l][p] += dp[i][j-1][l][s] * dp[i][j-1][s][p];
                        dp[i][j][l][p] %= K;
                    }
                }
            }
        }
    }
    vector<int> now; now.push_back(1);
    for (int i=0;i<n;i++){
        vector<int> nv;
        int dp2[63][16][16];
        for (int j=0;j<63;j++){
            for (int p=0;p<16;p++){
                for (int t=0;t<16;t++){
                    dp2[j][p][t] = 0;
                }
            }
        }
        for (int j=0;j<16;j++){
            dp2[0][j][j] = 1;
        }
        int counter = 0;
        for (int j=61;j>=0;j--){
            int aand = step[j] & (data[i][1] - data[i][0]);
            if (aand == 0) continue;
            counter ++;
            for (int p=0;p<16;p++){
                for (int s=0;s<16;s++){
                    for (int t=0;t<16;t++){
                        dp2[counter][p][s] += dp2[counter-1][p][t] * dp[data[i][2]][j][t][s];
                        dp2[counter][p][s] %= K;
                    }
                }
            }
        }
        for (int j=0;j<can[i+1].size();j++){
            int go = can[i+1][j];
            int our = 0;
            for (int p=0;p<can[i].size();p++){
                int el = can[i][p];
                our += dp2[counter][el][go] * now[p];
                our %= K;
            }
            nv.push_back(our);
        }
        now = nv;
    }
    cout << (now[0] + K) % K << endl;
    return 0;
}