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
int n, m, l, r;
bool ui;
vector<int> lefts;
vector<int> rights;
char ch;
int main(){
    ui = false;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        bool s = false;
        bool p = false;
        l = -1;
        r = -1;
        for (int j=0;j<m;j++){
            cin >> ch;
            if (!s){
                if (ch == 'X'){
                    l = j;
                    r = j;
                    s = true;
                }
            }
            else{
                if (ch == '.'){
                    p = true;
                }
                else{
                    r = j;
                    if (p){
                        ui = true;
                    }
                }
            }
        }
        lefts.push_back(l);
        rights.push_back(r);
    }
    bool ss = false;
    bool pp = false;
    int ll, rr;
    for (int i=0;i<n;i++){
        if (!ss){
            if (lefts[i] != -1){
                ll = lefts[i];
                rr = rights[i];
                ss = true;
            }
        }
        else{
            if (lefts[i] == -1){
                pp = true;
            }
            else{
                if (lefts[i] != ll | rights[i] != rr){
                    ui = true;
                }
                if (pp){
                    ui = true;
                }
            }
        }
    }
    if (ui){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}