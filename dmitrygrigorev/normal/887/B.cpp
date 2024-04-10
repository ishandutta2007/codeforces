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
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int v[n][6];
    for (int i=0; i < n; i++){
        for (int j=0; j < 6; j++) cin >> v[i][j];
    }
    set<int> num;
    for (int i=0; i < n; i++){
        for (int j=0; j < 6; j++) num.insert(v[i][j]);
    }
    if (n >= 2){
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                if (i == j) continue;
                for (int k=0; k < 6; k++){
                    for (int p=0; p <6; p++){
                        num.insert(v[i][k] + 10 * v[j][p]);
                    }
                }
            }
        }
    }
    if (n==3){
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                for (int k=0; k < n; k++){
                    if (i == k || j == k || i == j) continue;
                    for (int m=0; m < 6; m++){
                        for (int p=0; p < 6; p++){
                            for (int s=0; s < 6; s++){
                                num.insert(v[i][m] + 10 * v[j][p] + 100 * v[k][s]);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 1;
    while (true){
        if (!num.count(ans)){
            cout << ans-1 << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}