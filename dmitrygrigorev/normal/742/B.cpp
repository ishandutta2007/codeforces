#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
long long n, x, ai;
vector<long long> kol;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> x;
    for (int i=0;i<150000;i++){
        kol.push_back(0);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        kol[ai] ++;
    }
    if (x==0){
            long long ans = 0;
        for (int i=0;i<150000;i++){
            if (kol[i] >0){
                ans += kol[i] * (kol[i] - 1) / 2;
            }
        }
        cout << ans << endl;
        return 0;
    }
    vector<int> nx;
    for (int i=20;i>=0;i-=1){
        long long a = pow(2, i);
        if (x >= a){
            x -= a;
            nx.push_back(1);
        }
        else{
            nx.push_back(0);
        }
    }
    long long answer = 0;
    for (int i=0;i<150000;i++){
            if (kol[i] > 0){
            long long number = i;
        vector<int> sx;
        for (int j=20;j>=0;j-=1){
        long long a = pow(2, j);
        if (number >= a){
            number -= a;
            sx.push_back(1);
        }
        else{
            sx.push_back(0);
        }
    }
    long long aa = 0;
    for (int j=0;j<=20;j++){
        long long f = nx[j];
        long long s = sx[j];
        if (f != s){
            aa += pow(2, 20-j);
        }
    }
    answer += kol[i] * kol[aa];
    }
    }
    cout << answer / 2 << endl;
    return 0;

}