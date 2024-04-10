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
    string str;
    cin >> str;
    int r = 0;
    int b = 0;
    int g = 0;
    int y = 0;
    int now = 0;
    bool yy = false;
    bool rr = false;
    bool bb = false;
    bool gg = false;
    for (int j=0;j<4;j++){
    for (int i=j;i<str.size();i+=4){
        if (str[i] == 'R'){
            rr = true;
        }
        if (str[i] == 'B'){
            bb = true;
        }
        if (str[i] == 'G'){
            gg = true;
        }
        if (str[i] == 'Y'){
            yy = true;
        }
        if (str[i] == '!'){
            now ++;
        }
    }
    if (rr){
        r = now;
        rr = false;
    }
    if (yy){
        y = now;
        yy = false;
    }
    if (gg){
        g = now;
        gg = false;
    }
    if (bb){
        b = now;
        bb = false;
    }
    now = 0;
    }
    cout << r << " " << b << " " << y << " " << g << endl;
    return 0;
}