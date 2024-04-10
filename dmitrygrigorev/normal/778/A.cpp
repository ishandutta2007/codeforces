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
string s1, s2;
vector<int> data;
int ai;
bool bs(int counter){
    vector<bool> used;
    for (int i=0;i<s1.size();i++){
        used.push_back(false);
    }
    for (int i=0;i<counter;i++){
        int el = data[i] - 1;
        used[el] = true;
    }
    string sn = "";
    for (int i=0;i<s1.size();i++){
        if (!used[i]){
            sn += s1[i];
        }
    }
    int now_ans = 0;
    int cc = 0;
    while (now_ans < s2.size() && cc < sn.size()){
        if (sn[cc] == s2[now_ans]){
            now_ans ++;
        }
        cc ++;
    }
    if (now_ans < s2.size()){
        return false;
    }
    return true;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++){
        cin >> ai;
        data.push_back(ai);
    }
    int l = 0;
    int r = s1.size() + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (bs(m)){
            l = m;
        }
        else r = m;
    }
    cout << l << endl;
    return 0;
}