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
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    if (k * (min(a, b) + 1) < max(a, b)){
        cout << "NO" << endl;
        return 0;
    }
    string s = "";
    if (a>=b){
        int counter = 0;
        while (a != b){
            if (counter < k){
                s += "G";
                a -= 1;
                counter ++;
            }
            else{
                s += "B";
                b -= 1;
                counter = 0;
            }
        }
        while (a!=0){
            s += "BG";
            a-=1;
        }
    }
    else{
        int counter = 0;
        while (a != b){
            if (counter < k){
                s += "B";
                b -= 1;
                counter ++;
            }
            else{
                s += "G";
                a -= 1;
                counter = 0;
            }
        }
        while (a!=0){
            s += "GB";
            a-=1;
        }
    }
    cout << s << endl;
    return 0;
    
}