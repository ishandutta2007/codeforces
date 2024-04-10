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
vector<int> step;
int n;
int ai;
int main(){
    std::ios::sync_with_stdio(false);
    for (int i=0;i<60;i++){
        step.push_back(0);
    }
    cin >> n;
    vector<int> data;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
        int counter = 1;
        int ind = 0;
        while (true){
            if (counter <= ai && 2 * counter > ai){
                step[ind] ++;
                break;
            }
            counter *= 2;
            ind ++;
        }
        if (step[ind] > 2) {cout << "YES" << endl; return 0;}
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (data[i] < data[j] + data[k] && data[j] < data[i] + data[k] && data[k] < data[i] + data[j]){
cout << "YES" << endl; return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}