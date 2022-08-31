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
int n, ai, answer, constante;
vector<int> data;
vector<vector<int > > positions;
vector<int> step;
vector<int> mask(int number){
    int counter = 7;
    vector<int> help;
    while (counter >= 0){
        if (step[counter] > number){
            help.push_back(counter);
        }
        else{
            number -= step[counter];
        }
        counter --;
    }
    return help;
}
bool dynamics(int length){
    vector<vector< int > > dp;
    vector<int> used;
    for (int i=0;i<8;i++){
        used.push_back(0);
    }
    for (int i=0;i<n;i++){
        vector<int> help;
        help.push_back(0);
        for (int j=1;j<constante;j++){
            help.push_back(-1);
        }
        dp.push_back(help);
    }
    for (int i=0;i<8;i++){
        if (positions[i].size() >= length){
            dp[positions[i][length-1]][step[i]] = 0;
        }
        if (positions[i].size() >= length + 1){
            dp[positions[i][length]][step[i]] = 1;
        }
    }
    for (int i=0;i<n;i++){
        used[data[i]] += 1;
        for (int j=0;j<constante;j++){
            if (dp[i][j] != -1){
                vector<int> colours = mask(j);
                for (int m=0;m<colours.size();m++){
                    int colour = colours[m];
                    if (positions[colour].size() - used[colour] >= length){
                        dp[positions[colour][used[colour] + length-1]][j + step[colour]] = max(dp[positions[colour][used[colour] + length-1]][j + step[colour]], dp[i][j]);
                    }
                    if (positions[colour].size() - used[colour] >= length + 1){
                        dp[positions[colour][used[colour] + length]][j + step[colour]] = max(dp[positions[colour][used[colour] + length]][j + step[colour]], dp[i][j] + 1);
                    }
                }
                if (i+1 !=n){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                }
            }
        }
    }
    if (dp[n-1][constante - 1] == -1){
        return false;
    }
    else{
        answer = 8 * length + dp[n-1][constante - 1];
        return true;
    }
}
int main(){
    cin >> n;
    for (int i=0;i<8;i++){
        vector<int> help;
        positions.push_back(help);
    }
    int counter = 1;
    for (int i=0;i<8;i++){
        step.push_back(counter);
        counter = counter * 2;
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        positions[ai-1].push_back(i);
        data.push_back(ai-1);
    }
    int left = 0;
    int right = 125;
    constante = pow(2, 8);
    while (right - left > 1){
            int m = (left + right) / 2;
        if (dynamics(m)){
            left = m;
        }
        else{
            right = m;
        }
    }
    if (left > 0){
        cout << answer << endl;
    }
    else{
        int aa = 0;
        for (int i=0;i<8;i++){
            if (positions[i].size() > 0){
                aa ++;
            }
        }
        cout << aa << endl;
    }
    return 0;
}