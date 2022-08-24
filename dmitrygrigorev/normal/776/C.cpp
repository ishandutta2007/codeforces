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
int n;
long long k, ai;
vector<long long> steps;
map<long long, int> mymap;
long long CONST = pow(10, 15);
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 1){
        steps.push_back(1);
    }
    else if (k == -1){
        steps.push_back(1);
        steps.push_back(-1);
    }
    else{
        long long now = 1;
        while (abs(now) < CONST){
            steps.push_back(now);
            now = now * k;
        }
    }
    mymap[0] = 1;
    long long summ = 0;
    long long answer = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        summ += ai;
        for (int j=0;j<steps.size();j++){
             long long ns = steps[j];
             if (mymap.count(summ - ns)){
                answer += mymap[summ - ns];
             }
        }
        if (mymap.count(summ)){
            mymap[summ] += 1;
        }
        else mymap[summ] = 1;
    }
    cout << answer << endl;
    return 0;
}