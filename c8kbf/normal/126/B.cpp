#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef float _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+88;

_ nex[maxn], ans;
str a;

bool kmp(str sub, str s);
int main(int argc, char * argv[]) {
    
    cin >> a;
    a = " " + a;
    _ j = 0;
    for(_ i = 2; i < a.length(); i++) {
        while(j && a[j+1] != a[i]) j = nex[j];
        if(a[j+1] == a[i]) j++;
        nex[i] = j;
    }
    
    str sub = a.substr(2, a.length()-3);
    while(j) {
        if(kmp(sub, a.substr(1, j))) {
            cout << a.substr(1, j) << endl;
            exit(0);
        }
        j = nex[j];
    }
    
    cout << "Just a legend" << endl;
    
    return 0;
}

bool kmp(str sub, str s) {
    sub = " " + sub; s = " " + s;
    _ j = 0;
    for(_ i = 1; i < sub.length(); i++) {
        while(j && s[j+1] != sub[i]) j = nex[j];
        if(s[j+1] == sub[i]) j++;
        if(j == s.length()-1) return true;
    }
    return false;
}