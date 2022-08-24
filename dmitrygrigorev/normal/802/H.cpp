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
int n;
string s;
int c[101];
int32_t main(){
    cin >> n;
    for (int i=4;i<=100;i++){
        int now = 1;
        for (int j=0;j<4;j++){
            now *= (i - j);
        }
        for (int j=0;j<4;j++){
            now /= (j + 1);
        }
        c[i] = now;
    }
    for (int i=0;i<100;i++){
        s += 'b';
    }
    while (n > 0){
        int go;
        for (int i=4;i<=100;i++){
            if (c[i] > n) break;
            go = i;
        }
        string s1;
        int b = 0;
        bool flag = false;
        for (int i=0;i<s.size();i++){
            s1 += s[i];
            if (s[i] == 'b') b ++;
            if (!flag && b == 100 - go){
                s1 += 'a';
                flag = true;
            }
        }
        n -= c[go];
        s = s1;
    }
    cout << s << " " << "abbbb" << endl;
    return 0;
}