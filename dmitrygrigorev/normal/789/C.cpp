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
vector<long long> data;
long long a;
int main()
{
    cin >> n;
    long long nn = 0;
    for (int i=0;i<n;i++){
        cin >> a;
        data.push_back(a);
    }
    long long answer = -1;
    long long now = 0;
    long long mm = 0;
    for (int i=0;i<n-1;i++){
        if (i % 2 == 0){
            now += abs(data[i] - data[i + 1]);
            answer = max(answer, now + mm);
        }
        else{
            now -= abs(data[i] - data[i + 1]);
            answer = max(answer, now + mm);
            mm = max(mm + now, nn);
            now = 0;
        }
    }
    mm = 0;
    now = 0;
    for (int i=1;i<n-1;i++){
        if (i % 2 != 0){
            now += abs(data[i] - data[i + 1]);
            answer = max(answer, now + mm);
        }
        else{
            now -= abs(data[i] - data[i + 1]);
            answer = max(answer, now + mm);
            mm = max(mm + now, nn);
            now = 0;
        }
    }
    cout << answer << endl;
    return 0;
}