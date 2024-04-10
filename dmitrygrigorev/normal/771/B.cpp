/*
  !










*/
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
using namespace std;
int n, k;
string s;
string id = "ABCDEFGHIJKLMNOPQRSTUVWXYZAaAbAcAdAeAfAgAhAiAjAkAlAmAnAoApAqArAsAtAuAvAwAxAyAz";
vector<string> data;
int main()
{
    cin >> n >> k;
    vector<string> wanted;
    for (int i=0;i<26;i++){
        string help;
        help += id[i];
        wanted.push_back(help);
    }
    for (int i=0;i<26;i++){
        string help;
        help += id[26+2*i];
        help += id[26+2*i+1];
        wanted.push_back(help);
    }
    int ind;
    bool yes = false;
    for (int i=0;i<n-k+1;i++){
        cin >> s;
        if (!yes && s == "YES"){
            ind = i;
            yes = true;
        }
        data.push_back(s);
    }
    if (!yes){
        for (int i=0;i<n;i++){
            cout << "A" << " ";
        }
        return 0;
    }
    vector<int> answer;
    for (int i=0;i<k;i++){
        answer.push_back(i);
    }
    for (int i=ind+1;i<n-k+1;i++){
        string ss = data[i];
        if (ss == "YES"){
            set<int> used;
            for (int j=0;j<k-1;j++){
                used.insert(answer[answer.size() - j - 1]);
            }
            for (int j=0;j<k;j++){
                if (!used.count(j)){
                    answer.push_back(j);
                    break;
                }
            }
        }
        else{
            answer.push_back(answer[answer.size() - k + 1]);
        }
    }
    int ned = n - answer.size();
    while (ned > 0){
        ned --;
        vector<int> vect;
        vect.push_back(answer[0]);
        for (int i=0;i<answer.size();i++){
            vect.push_back(answer[i]);
        }
        answer = vect;
    }
    for (int i=0;i<n;i++){
        cout << wanted[answer[i]] << " ";
    }
    return 0;
}