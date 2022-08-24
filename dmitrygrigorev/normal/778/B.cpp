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
#include <unordered_map>
using namespace std;
int n, m;
unordered_map <string, int> mymap2;
string zapr[5000][5];
int main(){
    cin >> n >> m;
    string a, b, c, d, e;
    for (int i=0;i<n;i++){
        vector<string> hh;
        cin >> a >> b >> c;
        zapr[i][0] = a;
        zapr[i][1] = b;
        zapr[i][2] = c;
        if (c[0] == '0' || c[0] == '1'){
            zapr[i][3] = "^";
        }
        else{
            cin >> d >> e;
            zapr[i][3] = d;
            zapr[i][4] = e;
        }
    }
    string answer1 = "";
    string answer2 = "";
    for (int i=0;i<m;i++){
        short int sum1 = 0;
        short int sum2 = 0;
        for (int j=0;j<n;j++){
            if (zapr[j][3] == "^"){
                string s3 = "";
                s3 += zapr[j][2][i];
                sum1 += stoi(s3);
                mymap2[zapr[j][0]] = stoi(s3);
            }
            else{
                bool bit1, bit2;
                if (zapr[j][2] == "?"){
                    bit1 = 0;
                }
                else{
                    bit1 = mymap2[zapr[j][2]];
                }
                if (zapr[j][4] == "?"){
                    bit2 = 0;
                }
                else{
                    bit2 = mymap2[zapr[j][4]];
                }
                int res;
                if (zapr[j][3] == "OR"){
                    res = bit1 | bit2;
                }
                else if (zapr[j][3] == "XOR"){
                    res = bit1 ^ bit2;
                }
                else{
                    res = bit1 & bit2;
                }
                mymap2[zapr[j][0]] = res;
                sum1 += res;
            }
        }
        for (int j=0;j<n;j++){
            if (zapr[j][3] == "^"){
                string s3 = "";
                s3 += zapr[j][2][i];
                sum2 += stoi(s3);
                mymap2[zapr[j][0]] = stoi(s3);
            }
            else{
                int bit1, bit2;
                if (zapr[j][2] == "?"){
                    bit1 = 1;
                }
                else{
                    bit1 = mymap2[zapr[j][2]];
                }
                if (zapr[j][4] == "?"){
                    bit2 = 1;
                }
                else{
                    bit2 = mymap2[zapr[j][4]];
                }
                int res;
                if (zapr[j][3] == "OR"){
                    res = bit1 | bit2;
                }
                else if (zapr[j][3] == "XOR"){
                    res = bit1 ^ bit2;
                }
                else{
                    res = bit1 & bit2;
                }
                mymap2[zapr[j][0]] = res;
                sum2 += res;
            }
        }
        if (sum2 > sum1){
            answer2 += "1";
            answer1 += "0";
        }
        else if (sum1 > sum2){
            answer1 += "1";
            answer2 += "0";
        }
        else{
            answer1 += "0";
            answer2 += "0";
        }
    }
    cout << answer1 << endl;
    cout << answer2 << endl;
    return 0;
}