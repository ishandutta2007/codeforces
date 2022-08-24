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
int n;
string s;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '<') ans ++;
        else break;
    }
    for (int i=n-1;i>=0;i--){
        if (s[i] == '>') ans ++;
        else break;
    }
    cout << ans << endl;
    return 0;
}