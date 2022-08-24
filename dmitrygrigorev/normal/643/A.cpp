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
int n, ai;
vector<int> data, answer;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai-1);
        answer.push_back(0);
    }
    for (int i=0;i<n;i++){
        vector<int> result;
        for (int j=0;j<n;j++){
            result.push_back(0);
        }
        int maximum = 0;
        int ind = 2 * n;
        for (int j=i;j<n;j++){
            result[data[j]] ++;
            int rr = result[data[j]];
            if (rr < maximum || (rr == maximum && data[j] > ind)){
                answer[ind] ++;
            }
            else{
                ind  = data[j];
                maximum = rr;
                answer[ind] ++;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << answer[i] << " ";
    }
    return 0;
}