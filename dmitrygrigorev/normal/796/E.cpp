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
using namespace std;
short n, p, k, s, ai;
set<short> first, second;
set<short> un;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> k;
    short help = n / k;
    if (n % k != 0) help ++;
    cin >> s;
    for (int i=0;i<s;i++){
        cin >> ai;
        first.insert(ai);
        un.insert(ai);
    }
    cin >> s;
    for (int i=0;i<s;i++){
        cin >> ai;
        second.insert(ai);
        un.insert(ai);
    }
    if (p >= 2 * help){
        cout << un.size() << endl;
        return 0;
    }
    short dp[n+1][p+1][k+1][k+1];
    for (int i1=0;i1<=n;i1++){
        for (int i2=0;i2<=p;i2++){
            for (int i3=0;i3<=k;i3++){
                for (int i4=0;i4<=k;i4++){
                    dp[i1][i2][i3][i4] = -10000;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i1=1;i1<=n;i1++){
        for (int i2=0;i2<=p;i2++){
            for (int i3=0;i3<=k;i3++){
                for (int i4=0;i4<=k;i4++){
                    if (i3 == 0 && i4 == 0){
                        for (int i5=0;i5<=k;i5++){
                            for (int i6=0;i6<=k;i6++){
                                dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1-1][i2][i5][i6]);
                            }
                        }
                    }
                    else if (i3 == 0){
                        for (int i5=0;i5<=k;i5++){
                            short pl = 0;
                            short vz = 0;
                            if (second.count(i1)) pl++;
                            if (i4 == 1){
                                vz ++;
                            }
                            if (i2 - vz >= 0){
                                short ss = dp[i1-1][i2-vz][i5][i4-1] + pl;
                                dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], ss);
                            }
                        }
                    }
                    else if (i4 == 0){
                        for (int i5=0;i5<=k;i5++){
                            short vz = 0;
                            short pl = 0;
                            if (first.count(i1)) pl++;
                            if (i3 == 1){
                                vz ++;
                            }
                            if (i2 - vz >= 0){
                                short ss = dp[i1-1][i2-vz][i3-1][i5] + pl;
                                dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], ss);
                            }
                        }
                    }
                    else{
                        short vz = 0;
                        short pl = 0;
                        if (un.count(i1)) pl++;
                        if (i3 == 1){
                            vz ++;
                        }
                        if (i4 == 1){
                            vz ++;
                        }
                        if (i2 - vz >= 0){
                            short ss = dp[i1-1][i2-vz][i3-1][i4-1] + pl;
                            dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], ss);
                        }
                    }
                }
            }
            for (int i3=0;i3<=k;i3++){
                dp[i1][i2][0][i3] = max(dp[i1][i2][0][i3], dp[i1][i2][k][i3]);
            }
            for (int i3=0;i3<=k;i3++){
                dp[i1][i2][i3][0] = max(dp[i1][i2][i3][0], dp[i1][i2][i3][k]);
            }
        }
    }
    short ans = 0;
    for (int pp =0;pp<=p;pp++){
    for (int i=0;i<=k;i++){
        for (int j=0;j<=k;j++){
            ans = max(ans, dp[n][pp][i][j]);
        }
    }
    }
    cout << ans << endl;
    return 0;
}