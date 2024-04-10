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
void result(vector<int> answers){
    cout << "! ";
    for (int i=0;i<8;i++){
        cout << answers[i];
        cout << " ";
    }
}
void zapros(int x1, int y1, int x2, int y2){
    cout << "? ";
    cout << x1;
    cout << " ";
    cout << y1;
    cout << " ";
    cout << x2;
    cout << " ";
    cout << y2 << endl;
    cout.flush();

}
int main(){
    std::ios::sync_with_stdio(false);
    int n, answer;
    cin >> n;
    vector<int> east, west, north, south;
    int left = 0;
    int right = n;
    bool good;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, 1, m, n);
        cin >> answer;
        if (answer == 0){
            left = m;
        }
        else{
            right = m;
        }
    }
    zapros(1, 1, right, n);
    cin >> answer;
    if (answer == 1){
        good = false;
        east.push_back(right);
    }
    else{
            good = true;
        east.push_back(right);
        east.push_back(-1);
    }
    if (!good){
    int left = 0;
    int right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, 1, m, n);
        cin >> answer;
        if (answer != 2){
            left = m;
        }
        else{
            right = m;
        }
    }
    east.push_back(right);
    }


    left = 0;
    right = n + 1;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(m, 1, n, n);
        cin >> answer;
        if (answer == 0){
            right = m;
        }
        else{
            left = m;
        }
    }
    zapros(left, 1, n, n);
    cin >> answer;
    if (answer == 1){
        good = false;
        west.push_back(left);
    }
    else{
            good = true;
        west.push_back(left);
        west.push_back(-1);
    }
    if (!good){
    int left = 0;
    int right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(m, 1, n, n);
        cin >> answer;
        if (answer != 2){
            right = m;
        }
        else{
            left = m;
        }
    }
    west.push_back(left);
    }



    left = 0;
    right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, 1, n, m);
        cin >> answer;
        if (answer == 0){
            left = m;
        }
        else{
            right = m;
        }
    }
    zapros(1, 1, n, right);
    cin >> answer;
    if (answer == 1){
        good = false;
        north.push_back(right);
    }
    else{
            good = true;
        north.push_back(right);
        north.push_back(-1);
    }
    if (!good){
    int left = 0;
    int right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, 1, n, m);
        cin >> answer;
        if (answer != 2){
            left = m;
        }
        else{
            right = m;
        }
    }
    north.push_back(right);
    }


    left = 0;
    right = n + 1;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, m, n, n);
        cin >> answer;
        if (answer == 0){
            right = m;
        }
        else{
            left = m;
        }
    }
    zapros(1, left, n, n);
    cin >> answer;
    if (answer == 1){
        good = false;
        south.push_back(left);
    }
    else{
            good = true;
        south.push_back(left);
        south.push_back(-1);
    }
    if (!good){
    left = 0;
    right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        zapros(1, m, n, n);
        cin >> answer;
        if (answer != 2){
            right = m;
        }
        else{
            left = m;
        }
    }
    south.push_back(left);
    }
    vector<int>answers;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                for (int m=0;m<2;m++){
                    int ee = east[i];
                    int ss = south[j];
                    int ww = west[k];
                    int nn = north[m];
                    if (nn == -1 | ss == -1 | ee == -1 | ww == -1){
                        continue;
                    }
                    if (ss <= nn & ww <= ee){
                        zapros(ww, ss, ee, nn);
                        cin >> answer;
                        if (answer == 1){
                            bool b = true;
                            if (ww < ee){
                                zapros(ww + 1, ss, ee, nn);
                                cin >> answer;
                                if (answer == 1){
                                    b = false;
                                    continue;
                                }
                                zapros(ww, ss, ee - 1, nn);
                                cin >> answer;
                                if (answer == 1){
                                    b = false;
                                    continue;
                                }

                            }
                            if (ss < nn){
                                zapros(ww, ss + 1, ee, nn);
                                cin >> answer;
                                if (answer == 1){

                                    b = false;
                                    continue;
                                }
                                zapros(ww, ss, ee, nn - 1);
                                cin >> answer;
                                if (answer == 1){
                                    b = false;
                                    continue;
                                }
                            }
                            if (b){
                            answers.push_back(ww);
                            answers.push_back(ss);
                            answers.push_back(ee);
                            answers.push_back(nn);
                            }
                        }
                    }
                }
            }
        }
    }
    result(answers);
    return 0;
}