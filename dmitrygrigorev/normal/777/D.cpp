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
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    vector<string> sas;
    cin >> n;
    string s;
    for (int i=0;i<n;i++){
        cin >> s;
        sas.push_back(s);
    }
    for (int i=n-2;i>=0;i--){
        string sn = "#";
        for (int j=1;j<sas[i].size();j++){
            if (j >= sas[i+1].size()){
                break;
            }
            if (sas[i][j] < sas[i+1][j]){
                for (int k=j;k<sas[i].size();k++){
                    sn += sas[i][k];
                }
                break;
            }
            if (sas[i][j] == sas[i + 1][j]) {
                sn += sas[i][j];
                continue;
            }
            if (sas[i][j] > sas[i+1][j]) break;
        }
        sas[i] = sn;
    }
    for (int i=0;i<n;i++){
        cout << sas[i] << endl;
    }
    return 0;
}