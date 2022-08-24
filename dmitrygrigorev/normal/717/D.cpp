#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <algorithm>
#include <random>
#include <ctime>
#define int long long
using namespace std;
signed main(){
    int n, x;
    cin >> n >> x;
    vector<double> v(x+1);
    for (int i=0; i <= x; i++) cin >> v[i];
    double V[31][128];
    for (int i=0; i < 31; i++){
        for (int j=0; j < 128; j++) V[i][j] = 0;
    }
    for (int i=0; i <= x; i++) V[0][i] = v[i];
    for (int i=1; i < 31; i++){
        for (int j=0; j < 128; j++){
            for (int k=0; k < 128; k++){
                V[i][j^k] += V[i-1][j] * V[i-1][k];
            }
        }
    }
    cout.precision(30);
    double Ans[128];
    for (int j=0; j < 128; j++) Ans[j] = 0;
    bool th = false;
    for (int i=30 ; i>= 0; i--){
        int ba = n & (1LL << i);
        if (ba == 0) continue;
        if (!th){
            for (int j=0; j < 128; j++) Ans[j] = V[i][j];
            th = true;
            continue;
        }
        double A[128];
        for (int j=0; j < 128; j++) A[j] = 0;
        for (int j=0; j < 128; j++){
            for (int k=0; k < 128; k++){
                A[j^k] += Ans[j] * V[i][k];
            }
        }
        for (int j=0; j < 128; j++) Ans[j] = A[j];
    }
    cout << (double) 1 - Ans[0] << endl;
    return 0;
}