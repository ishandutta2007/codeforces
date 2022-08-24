#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int ai, di;
vector<int> data1;
vector<int> data2;
int main()
{
    long long inf = 100000000000;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai >> di;
        data1.push_back(ai);
        data2.push_back(di);
    }
    long long left = -inf;
    long long right = inf;
    for (int i=0;i<n;i++){
        int division = data2[i];
        if (division == 1){
            long long hh = 1900;
            left = max(left, hh);
        }
        else{
            long long hhh = 1899;
            right = min(right, hhh);
        }
        left += data1[i];
        right += data1[i];
    }
    if (left > right){
        cout << "Impossible" << endl;
        return 0;
    }
    if (right > 10000000000){
        cout << "Infinity" << endl;
        return 0;
    }
    cout << right << endl;
    return 0;
}