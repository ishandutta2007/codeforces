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
vector <int> data;
vector <int> dynamics;
vector <int> sums;
int main(){
    std::ios::sync_with_stdio(false);
    int n, ai;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += data[i];
        sums.push_back(sum);
    }
    dynamics.push_back(0);
    int maximum = sums.back();
    for (int i=1;i<n;i++){
        maximum = max(maximum, sums[n - i] - dynamics.back());
        dynamics.push_back(maximum);
    }
    cout << dynamics.back() << endl;
        return 0;
}