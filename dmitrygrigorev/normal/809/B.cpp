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
#define int long long
using namespace std;
int n, k;
string s;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int left = 1;
    int right = n;
    while (right - left > 1){
        int m1 = (right + left) / 2;
        int m2 = m1 + 1;
        cout << 1 << " " << m1 << " " << m2 << endl;
        cout.flush();
        cin >> s;
        if (s == "TAK"){
            right = m1;
        }
        else left = m2;
    }
    int f;
    int s1 = -1;
    int s2 = -1;
    if (left == right) f = left;
    else{
        cout << 1 << " " << left << " " << right << endl;
        cout.flush();
        cin >> s;
        if (s == "TAK"){
            f = left;
        }
        else f = right;
    }
    left = 1;
    right = f - 1;
    if (right >= left){
        while (right - left > 1){
            int m1 = (right + left) / 2;
            int m2 = m1 + 1;
            cout << 1 << " " << m1 << " " << m2 << endl;
            cout.flush();
            cin >> s;
            if (s == "TAK"){
                right = m1;
            }
            else left = m2;
        }
        if (left == right) s1 = left;
        else{
            cout << 1 << " " << left << " " << right << endl;
            cout.flush();
            cin >> s;
            if (s == "TAK"){
                s1 = left;
            }
            else s1 = right;
        }
    }
    left = f+1;
    right = n;
    if (right >= left){
        while (right - left > 1){
            int m1 = (right + left) / 2;
            int m2 = m1 + 1;
            cout << 1 << " " << m1 << " " << m2 << endl;
            cout.flush();
            cin >> s;
            if (s == "TAK"){
                right = m1;
            }
            else left = m2;
        }
        if (left == right) s2 = left;
        else{
            cout << 1 << " " << left << " " << right << endl;
            cout.flush();
            cin >> s;
            if (s == "TAK"){
                s2 = left;
            }
            else s2 = right;
        }
    }
    if (s1 != -1){
        cout << "1 " << s1 << " " << f << endl;
        cout.flush();
        cin >> s;
        if (s == "TAK"){
            cout << 2 << " " << f << " " << s1 << endl;
            cout.flush();
            return 0;
        }
    }
    cout << 2 << " " << f << " " << s2 << endl;
    cout.flush();
    return 0;
}