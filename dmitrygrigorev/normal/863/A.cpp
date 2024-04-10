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
#include <queue>
#include <deque>
#define int long long
#define D long double
using namespace std;
int32_t main(){
    string s;
    cin >> s;
    int g = s.size();
    for (int i=s.size()-1; i>= 0; i--){
        if (s[i] == '0') g--;
        else break;
    }
    string ss1 = "", ss2 = "";
    for (int i=0; i < g; i++){
        ss1 += s[i];
        ss2 += s[g-i-1];
    }
    if (ss1 == ss2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}