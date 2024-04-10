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
vector<char> first, second;
string f, s;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> f >> s;
    for (int i=0;i<f.size();i++){
        first.push_back(f[i]);
        second.push_back(s[i]);
    }
    string answer, answer1;
    sort(first.begin(), first.end(), greater<char>());
    sort(second.begin(), second.end());
    int m = 0;
    int ost = first.size();
    while (first.back() < second.back() && ost > 0){
        if (m == 0){
            answer += first.back();
            first.pop_back();
            ost --;
        }
        else{
            answer += second.back();
            second.pop_back();
            ost --;
        }
        m = 1 - m;
    }
    vector<char> f1, s1;
    int move1 = ost / 2;
    if (m == 0 && ost % 2 != 0){
        move1 ++;
    }
    int move2 = ost / 2;
    if (m == 1 && ost % 2 != 0){
        move2 ++;
    }
    for (int i=0;i<move1;i++){
        f1.push_back(first[first.size() - 1 - i]);
    }
    for (int i=0;i<move2;i++){
        s1.push_back(second[second.size() - 1 - i]);
    }
    while (ost > 0){
        if (m == 0){
            answer1 += f1.back();
            f1.pop_back();
            ost --;
        }
        else{
            answer1 += s1.back();
            s1.pop_back();
            ost --;
        }
        m = 1 - m;
    }
    if (answer1.size() > 0){
        for (int i=answer1.size() - 1;i>=0;i--){
            answer += answer1[i];
        }
    }
    cout << answer << endl;
    return 0;
}