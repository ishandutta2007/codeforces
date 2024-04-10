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
string str;
int n;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int d = 0;
    int r = 0;
    while (str.size() > 1){
    string s1 = "";
    for (int i=0;i<str.size();i++){
        if (str[i] == 'D'){
            if (d > 0){
                d --;
            }
            else{
                s1 += str[i];
                r ++;
            }
        }
        else{
            if (r > 0){
                r --;
            }
            else{
                s1 += str[i];
                d ++;
            }
        }
    }
    if (str == s1){
        str = s1;
        break;
    }
    str = s1;
    }
    if (str[0] == 'D'){
        cout << "D" << endl;
    }
    else{
        cout << "R" << endl;
    }
    return 0 ;
}