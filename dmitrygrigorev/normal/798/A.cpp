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
#define int long long
using namespace std;
string s;
string id = "abcdefghijklmnopqrstuvwxyz";
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i=0;i<s.size();i++){
        for (int j=0;j<26;j++){
            string s1 = s;
            s1[i] = id[j];
            string s2;
            for (int k=0;k<s.size();k++){
                s2 += s1[s.size() - k - 1];
            }
            if (s2 == s1 && s1 != s){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}