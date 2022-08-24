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
int n;
string s;
vector<int> stars, packmans;
bool checker(int number){
    int feat = 0;
    for (int i=0; i < packmans.size(); i++){
        if (feat == stars.size()) break;
        if (stars[feat] > packmans[i]){
            while (feat < stars.size() && stars[feat] - packmans[i] <= number){
                feat++;
            }
        }
        else{
            if (packmans[i] - stars[feat] > number) continue;
            int nn = packmans[i] - stars[feat];
            while (feat < stars.size() && packmans[i] - stars[feat] <= nn && packmans[i] - stars[feat] > 0){
                feat++;
            }
            while (feat < stars.size() && (stars[feat] - packmans[i] + 2*nn <= number || 2*stars[feat] - 2*packmans[i] + nn <= number)){
                feat++;
            }
        }
    }
    if (feat == stars.size()) return true;
    return false;
}
int32_t main(){
    cin >> n >> s;
    for (int i=0; i < n; i++){
        if (s[i] == 'P') packmans.push_back(i);
        if (s[i] == '*') stars.push_back(i);
    }
    int left = 0;
    int right = 10*n;
    while (right - left > 1){
        int mid = (right + left) / 2;
        if (checker(mid)){
            right = mid;
        }
        else left = mid;
    }
    cout << right << endl;
    return 0;
}