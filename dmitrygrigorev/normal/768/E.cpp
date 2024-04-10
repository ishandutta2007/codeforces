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
vector<int> data;
map<int, int> nm;
int ai;
int main(){
    std::ios::sync_with_stdio(false);
    int counter = 2;
    int zapas = 2;
    int nim = 1;
    cin >> n;
    for (int i=1;i<100;i++){
        nm[i] = nim;
        counter -= 1;
        if (counter == 0){
            counter = zapas + 1;
            zapas += 1;
            nim += 1;
        }
    }
    int xors = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        xors = xors ^ nm[ai];
    }
    if (xors == 0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}