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
int32_t main(){
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            char ch;
            cin >> ch;
            matrix[i][j] = ch - '0';
        }
    }
    int prefix[n][m+1];
    for (int i=0; i < n; i++){
        int summ = 0;
        prefix[i][0] = 0;
        for (int j=0; j < m; j++){
            summ += matrix[i][j];
            prefix[i][j+1] = summ;
        }
    }
    int ans = 1e18;
    for (int i=2; i < max(n, m); i++){
        int th = 0;
        for (int j=0; j < n; j+=i){
            for (int st=0; st < m; st += i){
                int number = 0;
                for (int k=j; k < j+i; k++){
                    if (k < n){
                        number += prefix[k][min(st+i, m)] - prefix[k][st];
                    }
                    else break;
                }
                number = min(number, i*i - number);
                th += number;
            }
        }
        ans = min(ans, th);
    }
    cout << ans << endl;
    return 0;
}