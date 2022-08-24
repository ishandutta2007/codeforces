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
int p;
bool l, r, n, s;
int main(){
    cin >> p;
    r = false;
    l = false;
    n = false;
    s = false;
    string str;
    cin >> str;
    int counter = 0;
    for (int i=0;i<p;i++){
        if (str[i] == 'U'){
            if (s){
                counter ++;
                r = false;
                l = false;
                n = true;
                s = false;
            }
            else{
                n = true;
            }
        }
        if (str[i] == 'D'){
            if (n){
                counter ++;
                r = false;
                l = false;
                s = true;
                n = false;
            }
            else{
                s = true;
            }
        }
        if (str[i] == 'L'){
            if (r){
                counter ++;
                r = false;
                n = false;
                l = true;
                s = false;
            }
            else{
                l = true;
            }
        }
        if (str[i] == 'R'){
            if (l){
                counter ++;
                n = false;
                l = false;
                r = true;
                s = false;
            }
            else{
                r = true;
            }
        }
    }
    counter ++;
    cout << counter << endl;
    return 0;
    
}