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
int n, q, ti, ki, qi;
vector<int> endt;
vector<int> answers;
int main(){
    cin >> n >> q;
    for (int i=0;i<n;i++){
        endt.push_back(-1);
    }
    for (int i=0;i<q;i++){
        cin >> ti >> ki >> qi;
        int aa = 0;
        int kk = ki;
        for (int j=0;j<n;j++){
            if (endt[j] <= ti){
                ki -= 1;
                aa += j + 1;
            }
            if (ki == 0){
                break;
            }
        }
        if (ki == 0){
            answers.push_back(aa);
            for (int j=0;j<n;j++){
            if (endt[j] <= ti){
                endt[j] = ti + qi;
                kk -= 1;
            }
            if (kk == 0){
                break;
            }
            }
        }
        else{
            answers.push_back(-1);
        }
    }
    for (int i =0;i<q;i++){
        cout << answers[i] << endl;
    }
    return 0;
}