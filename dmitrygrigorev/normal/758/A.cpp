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
int main(){
    std::ios::sync_with_stdio(false);
    vector<long long> data;
    long long ai;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    long long answer = 0;
    for (int i=0;i<n-1;i++){
        answer += (abs(data[i] - data[n - 1]));
    }
    cout << answer << endl;
    return 0;
}