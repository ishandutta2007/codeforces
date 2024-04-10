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
#include <time.h>
#define int long long
using namespace std;
int n, m, ai;
vector<vector<int> > data;
int K = pow(10, 9);
int32_t main() {
    cin >> n >> m;
    for (int i=0;i<n;i++){
        vector<int> help;
        for (int j=0;j<m;j++){
            cin >> ai;
            help.push_back(ai);
        }
        data.push_back(help);
    }
    int moves = 0;
    vector<vector<int> > ans;
    if (n <= m){
        for (int i=0;i<n;i++){
            int minimum = K;
            for (int j=0;j<m;j++){
                minimum = min(minimum, data[i][j]);
            }
            if (minimum > 0){
                moves += minimum;
                for (int j=0;j<m;j++){
                    data[i][j] -= minimum;
                }
                for (int j=0;j<minimum;j++){
                vector<int> help;
                help.push_back(0);
                help.push_back(i);
                ans.push_back(help);
                }
            }
        }
        for (int i=0;i<m;i++){
            int minimum = K;
            for (int j=0;j<n;j++){
                minimum = min(minimum, data[j][i]);
            }
            if (minimum > 0){
                moves += minimum;
                for (int j=0;j<n;j++){
                    data[j][i] -= minimum;
                }
                for (int j=0;j<minimum;j++){
                vector<int> help;
                help.push_back(1);
                help.push_back(i);
                ans.push_back(help);
                }
            }
        }
    }
    else{
        for (int i=0;i<m;i++){
            int minimum = K;
            for (int j=0;j<n;j++){
                minimum = min(minimum, data[j][i]);
            }
            if (minimum > 0){
                moves += minimum;
                for (int j=0;j<n;j++){
                    data[j][i] -= minimum;
                }
                for (int j=0;j<minimum;j++){
                vector<int> help;
                help.push_back(1);
                help.push_back(i);
                ans.push_back(help);
                }
            }
        }
        for (int i=0;i<n;i++){
            int minimum = K;
            for (int j=0;j<m;j++){
                minimum = min(minimum, data[i][j]);
            }
            if (minimum > 0){
                moves += minimum;
                for (int j=0;j<m;j++){
                    data[i][j] -= minimum;
                }
                for (int j=0;j<minimum;j++){
                vector<int> help;
                help.push_back(0);
                help.push_back(i);
                ans.push_back(help);
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (data[i][j] != 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << moves << endl;
    for (int i=0;i<moves;i++){
        if (ans[i][0] == 0) cout << "row ";
        else cout << "col ";
        cout << ans[i][1] + 1 << endl;
    }
    return 0;
}