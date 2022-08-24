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
int n, ai;
char ch;
set<int> used;
vector<int> length;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ch;
        if (ch == '>') length.push_back(1);
        else length.push_back(-1);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        length[i] = length[i] * ai;
    }
    int now = 0;
    used.insert(0);
    while (true){
        now = now + length[now];
        if (used.count(now)){
            cout << "INFINITE" << endl;
            return 0;
        }
        if (now < 0 || now >= n){
            cout << "FINITE" << endl;
            return 0;
        }
        used.insert(now);
    }
    return 0;
}