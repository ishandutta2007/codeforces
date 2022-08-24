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
int n, ai;
vector<int> data;
int bs(int element){
    int l = 0;
    int r = n;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (data[m] <= element){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    vector<long long> answers;
    answers.push_back(0);
    for (int i=0;i<n;i++){
        answers.push_back(1000000000000);
    }
    for (int i=1;i<=n;i++){
        long long last_summ = answers[i-1];
        answers[i] = min(answers[i], last_summ + 20);
        int pos1 = bs(data[i - 1] + 89) + 1;
        for (int j=i;j<=pos1;j++){
            answers[j] = min(answers[j], last_summ + 50);
        }
        int pos2 = bs(data[i - 1] + 1439) + 1;
        for (int j=i;j<=pos2;j++){
            answers[j] = min(answers[j], last_summ + 120);
        }
    }
    int del = 0;
    for (int i=1;i<=n;i++){
        int price = answers[i];
        cout << price - del << endl;
        del += (price - del);
    }
    return 0;
}