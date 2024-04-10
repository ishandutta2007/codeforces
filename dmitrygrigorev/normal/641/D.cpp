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
using namespace std;
int n;
vector<double> first, second;
double eps = 0.0000001;
double ai;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        first.push_back(ai);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        second.push_back(ai);
    }
    double s1 = 0;
    double s2 = 0;
    vector<double> a1, a2;
    for (int i=0;i<n;i++){
        double x = first[i];
        double y = second[i];
        double a = 1;
        double b = - (s1 + x + y - s2);
        double c = - (x * s2 + y * s2 - x);
        double disc = b * b - 4 * a * c;
        if (disc >= -eps && disc < 0){
            disc = 0;
        }
        disc = sqrt(disc);
        double k1 = (-b + disc) / 2;
        double k2 = (-b - disc) / 2;
        double nn = 0;
        if (k1 <= k2) swap(k1, k2);
        if (k1 >= -eps && k1 <= x + y + eps){
            s2 += max(k1, nn);
            s1 += max(nn, x + y - k1);
            a2.push_back(max(k1, nn));
            a1.push_back(max(nn, x + y - k1));
        }
        else{
            s2 += max(k2, nn);
            s1 += max(nn, x + y - k2);
            a2.push_back(max(k2, nn));
            a1.push_back(max(nn, x + y - k2));
        }
    }
    cout.precision(25);
    for (int i=0;i<n;i++){
        cout << a1[i] << " ";
    }
    cout << endl;
    for (int i=0;i<n;i++){
        cout << a2[i] << " ";
    }
    return 0;
}