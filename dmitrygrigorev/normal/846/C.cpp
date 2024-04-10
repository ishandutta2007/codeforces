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
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int data[n];
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    int sums[n+1];
    sums[0] = 0;
    for (int i=0; i < n; i++){
        sums[i+1] = sums[i] + data[i];
    }
    int best[n+1];
    int b[n+1];
    for (int i=n; i >= 0; i--){
        int ba = -1e18;
        int x;
        for (int j=i; j <= n; j++){
            int var = sums[j] - sums[i] - sums[n] + sums[j];
            if (var > ba){
                ba = var;
                x = j;
            }
        }
        b[i] = x;
        best[i] = ba;
    }
    int a, bb, c;
    int cand = -1e18;
    for (int i=0; i <= n; i++){
        for (int j=i; j <= n; j++){
            int var = sums[i] - sums[0] - sums[j] + sums[i] + best[j];
            if (var > cand){
                a = i;
                bb = j;
                c = b[j];
                cand = var;
            }
        }
    }
    cout << a << " " << bb << " " << c << endl;
    return 0;
}