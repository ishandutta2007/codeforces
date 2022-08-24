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
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    string s1 = "", s2 = "";
    for (int i=0; i < n; i++){
        s1 += '0';
        s2 += '0';
    }
    s2[0] = '1';
    cout << "? " << s1 << endl;
    cout.flush();
    int h1;
    cin >> h1;
    cout << "? " << s2 << endl;
    cout.flush();
    int h2;
    cin >> h2;
    char symb;
    if (h1 < h2) symb = '0';
    else symb = '1';
    int hamming;
    string str;
    for (int i=0; i < n; i++){
        str.push_back(symb);
    }
    cout << "? " << str << endl;
    cout.flush();
    cin >> hamming;
    int left = 0;
    int right = n-1;
    while (right - left > 1){
        int mid = (left + right) / 2;
        string ss = str;
        for (int j=0; j < mid; j++){
            if (symb == '0') ss[j+1] = '1';
            else ss[j+1] = '0';
        }
        cout << "? " << ss << endl;
        cout.flush();
        int rr;
        cin >> rr;
        if (rr - mid == hamming) left = mid;
        else right = mid;
    }
    if (symb == '0'){
        cout << "! " << 1 << " " << 2+left << endl;
    }
    else cout << "! " << 2+left << " " << 1 << endl;
    cout.flush();
    return 0;
}