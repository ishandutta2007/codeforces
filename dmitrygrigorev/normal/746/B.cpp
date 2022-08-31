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
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    string s = "";
    if (n % 2 == 0){
        while (n > 0){
            s = str[0] + s;
            s += str[1];
            n -= 2;
            string ss="";
            for (int i=2;i<str.size();i++){
                ss += str[i];
            }
            str = ss;
        }
    }
    else{
        s = str[0];
        string sss = "";
        for (int i=0;i<n;i++){
            if (i!=0){
                sss += str[i];
            }
        }
        n-=1;
        str = sss;
        while (n > 0){
            s = str[0] + s;
            s += str[1];
            n -= 2;
            string ss="";
            for (int i=2;i<str.size();i++){
                ss += str[i];
            }
            str = ss;
        }
    }
    cout << s << endl;
    return 0;
    
}