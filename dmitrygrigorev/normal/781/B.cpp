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
string s;
map<string, int> mymap;
vector<string> ss;
vector<string> uk;
set<string> myset;
vector<string> answer;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        string ps = "";
        answer.push_back(ps);
        cin >> s;
        string sss = "";
        for (int j=0;j<3;j++){
            sss += s[j];
        }
        if (!mymap.count(sss)){
            mymap[sss] = 1;
        }
        else mymap[sss] += 1;
        uk.push_back(sss);
        cin >> s;
        sss = "";
        sss += s[0];
        ss.push_back(sss);
    }
    int counter = 0;
    for (int i=0;i<n;i++){
        s = uk[i];
        if (mymap[s] > 1){
            string mystring;
            for (int j=0;j<2;j++){
            mystring += s[j];
        }
            mystring += ss[i];
            if (myset.count(mystring)) {cout << "NO" << endl; return 0;}
            else myset.insert(mystring);
            answer[i] = mystring;
            counter += 1;
        }
    }
    while (counter < n){
        bool change = false;
        for (int i=0;i<n;i++){
            s = uk[i];
            if (answer[i] == ""){
                string s2;
                for (int j=0;j<2;j++){
            s2 += s[j];
        }
                s2 += ss[i];
                if (myset.count(s) && myset.count(s2)){
                    cout << "NO" << endl; return 0;
                }
                if (!myset.count(s) && !myset.count(s2)){
                    continue;
                }
                change = true;
                if (myset.count(s)){
                    myset.insert(s2);
                    answer[i] = s2;
                    counter ++;
                }
                else{
                    myset.insert(s);
                    answer[i] = s;
                    counter ++;
                }
            }
        }
        if (!change) break;
    }
    for (int i=0;i<n;i++){
        if (answer[i] == ""){
            answer[i] = uk[i];
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        cout << answer[i] << endl;
    }
    return 0;
}