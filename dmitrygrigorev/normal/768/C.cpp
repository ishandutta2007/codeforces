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
using namespace std;
int n, k, x, ai;
vector<int> data;
int main(){
    cin >> n >> k >> x;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    k = k % 64;
    for (int i=0;i<k;i++){
        sort(data.begin(), data.end());
        vector<int> data1;
        for (int j=0;j<data.size();j++){
            if (j % 2 == 0){
                data1.push_back(data[j] ^ x);
            }
            else{
                data1.push_back(data[j]);
            }
        }
        data = data1;
    }
    sort(data.begin(), data.end());
    cout << data[n - 1] << " " << data[0] << endl;
    return 0;
}