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
    int n;
    long long x, y, x1, y1;
    cin >> n >> x >> y;
    string s;
    vector<vector<int> > h;
    for (int i=0;i<8;i++){
        vector<int> hh;
        hh.push_back(-1);
        hh.push_back(-1);
        hh.push_back(-1);
        h.push_back(hh);
    }
    for (int i=0;i<n;i++){
        cin >> s >> x1 >> y1;
        if (x == x1){
            if (y < y1){
                if (h[0][0] == -1 || h[0][2] > y1){
                    h[0][1] = x1;
                    h[0][2] = y1;
                    if (s == "Q"){
                        h[0][0] = 1;
                    }
                    if (s == "R"){
                        h[0][0] = 2;
                    }
                    if (s == "B"){
                        h[0][0] = 3;
                    }
                }
            }
            else{
                if (h[1][0] == -1 || h[1][2] < y1){
                    h[1][1] = x1;
                    h[1][2] = y1;
                    if (s == "Q"){
                        h[1][0] = 1;
                    }
                    if (s == "R"){
                        h[1][0] = 2;
                    }
                    if (s == "B"){
                        h[1][0] = 3;
                    }
                }
            }
        }
        if (y == y1){
            if (x < x1){
                if (h[2][0] == -1 || h[2][1] > x1){
                    h[2][1] = x1;
                    h[2][2] = y1;
                    if (s == "Q"){
                        h[2][0] = 1;
                    }
                    if (s == "R"){
                        h[2][0] = 2;
                    }
                    if (s == "B"){
                        h[2][0] = 3;
                    }
                }
            }
            else{
                if (h[3][0] == -1 || h[3][1] < x1){
                    h[3][1] = x1;
                    h[3][2] = y1;
                    if (s == "Q"){
                        h[3][0] = 1;
                    }
                    if (s == "R"){
                        h[3][0] = 2;
                    }
                    if (s == "B"){
                        h[3][0] = 3;
                    }
                }
            }
        }
    if (x - x1 == y - y1){
            if (y < y1){
                if (h[4][0] == -1 || h[4][2] > y1){
                    h[4][1] = x1;
                    h[4][2] = y1;
                    if (s == "Q"){
                        h[4][0] = 1;
                    }
                    if (s == "R"){
                        h[4][0] = 2;
                    }
                    if (s == "B"){
                        h[4][0] = 3;
                    }
                }
            }
            else{
                if (h[5][0] == -1 || h[5][2] < y1){
                    h[5][1] = x1;
                    h[5][2] = y1;
                    if (s == "Q"){
                        h[5][0] = 1;
                    }
                    if (s == "R"){
                        h[5][0] = 2;
                    }
                    if (s == "B"){
                        h[5][0] = 3;
                    }
                }
            }
        }
        if (x - x1 == -(y - y1)){
            if (y < y1){
                if (h[6][0] == -1 || h[6][2] > y1){
                    h[6][1] = x1;
                    h[6][2] = y1;
                    if (s == "Q"){
                        h[6][0] = 1;
                    }
                    if (s == "R"){
                        h[6][0] = 2;
                    }
                    if (s == "B"){
                        h[6][0] = 3;
                    }
                }
            }
            else{
                if (h[7][0] == -1 || h[7][2] < y1){
                    h[7][1] = x1;
                    h[7][2] = y1;
                    if (s == "Q"){
                        h[7][0] = 1;
                    }
                    if (s == "R"){
                        h[7][0] = 2;
                    }
                    if (s == "B"){
                        h[7][0] = 3;
                    }
                }
            }
        }
    }
    bool ans = false;
    for (int i=0;i<4;i++){
        if (h[i][0] == 1 || h[i][0] == 2){
            ans = true;
        }
    }
    for (int i=4;i<8;i++){
        if (h[i][0] == 1 || h[i][0] == 3){
            ans = true;
        }
    }
    if (ans){
         cout << "YES" << endl;   
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}