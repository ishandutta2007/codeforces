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
vector<string> data;
vector<vector<int> > ss;
vector<int> money;
map <string, vector<int> > mymap; 
int n, k, ai;
string str;
string rever(string sss){
    string z = "";
    for (int i=k-1;i>=0;i--){
        z += sss[i];
    }
    return z;
}
int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> str;
        data.push_back(str);
        cin >> ai;
        money.push_back(ai);
        vector<int> help;
        help.push_back(ai);
        help.push_back(i);
        ss.push_back(help);
    }
    sort(ss.begin(), ss.end());
    int answer = 0;
    for (int i=0;i<n;i++){
        int counter = ss[i][1];
            if (!mymap.count(data[counter])){
                vector<int> help;
                help.push_back(money[counter]);
                mymap[data[counter]] = help;
            }
            else{
                mymap[data[counter]].push_back(money[counter]);
            }
    }
    int profit = 0;
    for (int i=0;i<n;i++){
        string dop = rever(data[i]);
        if (dop != data[i]){
        if (mymap.count(data[i]) & mymap.count(dop)){
            while (mymap[data[i]].size() > 0 & mymap[dop].size() > 0){
                if (mymap[data[i]].back() + mymap[dop].back() > 0){
                    answer += mymap[data[i]].back() + mymap[dop].back();
                    mymap[data[i]].pop_back();
                    mymap[dop].pop_back();
                }
                else{
                    break;
                }
            }
        }
        }
        else{
            while (mymap[dop].size() > 1){
                if (mymap[dop][mymap[dop].size()-1] +mymap[dop][mymap[dop].size()-2] > 0){
                    answer += mymap[dop][mymap[dop].size()-1] +mymap[dop][mymap[dop].size()-2];
                    profit = max(profit, -mymap[dop][mymap[dop].size()-2]);
                    for (int i=0;i<2;i++){
                        mymap[dop].pop_back();
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    int maximum = 0;
    for (int i=0;i<n;i++){
        string dop = rever(data[i]);
        if (dop == data[i]){
            if (mymap.count(dop)){
                if (mymap[dop].size() > 0){
                    maximum = max(mymap[dop][mymap[dop].size()-1], maximum);
                }
            }
        }
    }
    answer += max(maximum, profit);
    cout << answer << endl;
    return 0;
    
}