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
int n, ai, summ;
vector<int> data;
vector<int> sums, nexts, prevs;
bool checker(int mid){
    int ww = mid;
    if (mid * 11 > summ) return false;
    int gr;
    for (int i=n-1; i>=0 ;i--){
        if (data[i] > mid){
            gr = i;
            break;
        }
        mid -= data[i];
    }
    if (mid == 0) return true;
    if (data[gr] == 1000) return true;
    if (data[gr] == 2000 && mid > 1000) return true;
    if (sums[gr] >= 10 * ww) return true;
    if (nexts[gr] != n-1 && nexts[gr] != -1) return true;
    if (prevs[gr] == -1) return false;
    int ind = prevs[gr];
    if (sums[ind] >= 10*(mid)) return true;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    cin >> n;
    summ = 0;
    sums.push_back(summ);
    for (int i=0; i < n; i++){
        cin >> ai;
        summ += ai;
        sums.push_back(summ);
        data.push_back(ai);
    }
    if (data[0] == 1000) prevs.push_back(0);
    else prevs.push_back(-1);
    for (int i=0; i < n; i++){
        nexts.push_back(-1);
    }
    if (data[n-1] == 1000) nexts[n-1] = n-1;
    else nexts[n-1] = -1;
    for (int i=1; i < n; i++){
        if (data[i] == 1000) prevs.push_back(i);
        else prevs.push_back(prevs[i-1]);
    }
    for (int i=n-2; i >= 0; i--){
        if (data[i] == 1000) nexts[i] = i;
        else nexts[i] = nexts[i+1];
    }
    int left = 0;
    int right = summ/100 + 2;
    while (right - left > 1){
        int mid = (left + right) / 2;
        bool res = checker(100*mid);
        if (res) left = mid;
        else right = mid;
    }
    cout << summ-left*100 << endl;
    return 0;
}