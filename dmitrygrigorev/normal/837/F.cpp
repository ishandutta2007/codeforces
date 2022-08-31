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
int MAX = 2e6;
int32_t main(){
    int n;
    int k, ai;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<int> data;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    vector<vector<int> > v;
    vector<int> help;
    for (int i=0; i < n; i++){
        help.push_back(0);
        if (data[i] >= k){
            cout << 0 << endl;
            return 0;
        }
    }
    help[0] = 1;
    v.push_back(help);
    for (int i=1; i <= MAX; i++){
        int summ = 0;
        vector<int> help;
        for (int j = 0; j < v.back().size(); j++){
            summ += v.back()[j];
            if (summ >= k) break;
            help.push_back(summ);
        }
        v.push_back(help);
    }
    int left = 0;
    int right = 2e18;
    while (right - left > 1){
        int mid = (left + right) / 2;
        int summ = 0;
        for (int i=0; i < n; i++){
            int sst = n - i - 1;
            if (mid > MAX){
                if (sst == 0) summ += data[i];
                else if (sst >= 3){
                    if (data[i] > 0) summ = k;
                }
                else{
                    int num;
                    if (sst == 2) {
                        if (mid <= 2e9) num = mid * (mid + 1) / 2;
                        else num = k;
                    }
                    else num = mid;
                    int max_d = k / num;
                    if (data[i] > max_d){
                        summ = k;
                        break;
                    }
                    else summ += data[i] * num;
                }
                if (summ >= k) break;
            }
            else{
                if (sst >= v[mid].size()){
                    if (data[i] > 0) summ = k;
                }
                else{
                    int num = v[mid][sst];
                    int max_d = k / num;
                    if (data[i] > max_d){
                        summ = k;
                        break;
                    }
                    else summ += data[i] * num;
                }
                if (summ >= k) break;
            }
        }
        if (summ >= k) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}