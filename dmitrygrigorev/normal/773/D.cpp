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
int data[2000][2000];
int answer[2000];
bool used[2000];
int n, ai;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int maximum = pow(10, 15);
    cin >> n;
    for (int i=0;i<n;i++){
        used[i] = false;
        for (int j=i+1;j<n;j++){
            cin >> ai;
            maximum = min(ai, maximum);
            data[i][j] = ai;
            data[j][i] = ai;
        }
    }
    for (int i=0;i<n;i++){
        int mini = pow(10, 15);
        for (int j=0;j<n;j++){
            if (i==j) continue;
            data[i][j] -= maximum;
            mini = min(data[i][j], mini);
        }
        answer[i] = 2 * mini;
    }
    for (int i=0;i<n;i++){
        int mini = pow(10, 15);
        int ind;
        for (int j=0;j<n;j++){
            if (!used[j]) {
                if (mini > answer[j]){
                    ind = j;
                    mini = answer[j];
                }
            }
        }
        used[ind] = true;
        for (int i=0;i<n;i++){
            if (!used[i]){
                answer[i] = min(answer[i], answer[ind] + data[ind][i]);
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << answer[i] + (n-1) * maximum << endl;
    }
    return 0;
}