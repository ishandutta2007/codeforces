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
vector<double> data;
int main(){
    std::ios::sync_with_stdio(false);
    int n, n1, n2;
    double a;
    cin >> n >> n1 >> n2;
    for (int i=0;i<n;i++){
        cin >> a;
        data.push_back(a);
    }
    sort(data.begin(), data.end());
    double a1 = 0;
    double a2 = 0;
    double a3 = 0;
    double a4 = 0;
    int start = n - n1 - n2;
    for (int i=start;i<n-n2;i++){
        a1 += data[i];
    }
    for (int i=n-n2;i<n;i++){
        a2 += data[i];
    }
    for (int i=start;i<n-n1;i++){
        a3 += data[i];
    }
    for (int i=n-n1;i<n;i++){
        a4 += data[i];
    }
    cout.precision(20);
    cout << max(a1 / n1 + a2 / n2, a3 / n2 + a4 / n1) << endl;
    return 0;
}