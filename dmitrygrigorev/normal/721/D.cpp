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
vector<vector< double > > tree;
void modificate(){
    int counter = 0;
    while (2 * counter + 1 < tree.size()){
        int first = 2 * counter + 1;
        int second = 2 * counter + 2;
        if (second < tree.size()){
            if (tree[counter][0] <= tree[first][0] & tree[counter][0] <= tree[second][0]){
                break;
            }
            if (tree[second][0] > tree[first][0]){
                std::swap(tree[first], tree[counter]);
                counter = first;
            }
            else{
                std::swap(tree[second], tree[counter]);
                counter = second;
            }
        }
        else{
            if (tree[counter][0] <= tree[first][0]){
                break;
            }
            std::swap(tree[first], tree[counter]);
            counter = first;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    double x, ai;
    cin >> n >> k >> x;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    for (int i=0;i<n;i++){
        vector<double> help;
        help.push_back(abs(data[i]));
        help.push_back(data[i] >= 0);
        help.push_back(i);
        tree.push_back(help);
    }
       sort(tree.begin(), tree.end());
    bool change = true;
    for (int i=0;i<n;i++){
        if (tree[i][1] == false){
            change = 1 - change;
        }
    }
    if (change){
        double number = tree[0][0];
        if (!tree[0][1]){
            number = number * (-1);
        }
        if (number >= 0){
            while (number >= 0 & k > 0){
                number -= x;
                k -= 1;
            }
            if (number < 0){
                tree[0][1] = false;
            }
            tree[0][0] = abs(number);
        }
        else{
            while (number <= 0 & k > 0){
                number += x;
                k -= 1;
            }
            if (number > 0){
                tree[0][1] = true;
            }
            tree[0][0] = abs(number);
        }
    }
    sort(tree.begin(), tree.end());
    for (int i=0;i<k;i++){
        modificate();
        tree[0][0] += x;
    }
    vector<double> answer;
    for (int i=0;i<n;i++){
        answer.push_back(0);
    }
    for (int i=0;i<n;i++){
        double number = tree[i][0];
        if (!tree[i][1] & number != 0){
            number = number * (-1);
        }
        answer[tree[i][2]] = number;
    }
    cout.precision(15);
    for (int i=0;i<n;i++){
        cout << answer[i] << " ";
    }
    return 0;
}