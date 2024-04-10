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
vector <vector <int> > data;
int answer;
int main(){
    int n, m, h;
    answer = 0;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        vector<int> help;
        for (int j=0;j<m;j++){
        cin >> h;
        help.push_back(h);
        }
        data.push_back(help);
    }
    int counter = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (data[i][j] == 1){
                answer += counter;
                counter = 0;
            }
            else{
                counter ++;
            }
        }
        counter = 0;
    }
    counter = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (data[i][m - j - 1] == 1){
                answer += counter;
                counter = 0;
            }
            else{
                counter += 1;
            }
        }
        counter = 0;
    }
    counter = 0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (data[j][i] == 1){
                answer += counter;
                counter = 0;
            }
            else{
                counter += 1;
            }
        }
        counter = 0;
    }
    counter = 0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (data[n - j - 1][i] == 1){
                answer += counter;
                counter = 0;
            }
            else{
                counter += 1;
            }
        }
        counter = 0;
    }
    cout << answer << endl;
    return 0;
}