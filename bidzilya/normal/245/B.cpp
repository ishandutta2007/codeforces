#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int main(){
    string s;
    cin >> s;
    int pos;
    if (s[0]=='h' && s[1]=='t' && s[2]=='t' && s[3]=='p'){
        cout << "http://";
        pos = 4;
    }else{
        cout << "ftp://";
        pos = 3;
    }
    cout << s[pos++];
    while (!(s[pos]=='r' && s[pos+1]=='u'))
        cout << s[pos++];
    cout << ".ru";
    pos += 2;
    if (pos<s.length()){
        cout << "/";
        while (pos<s.length())
            cout << s[pos++];
    }
    cout << endl;
    return 0;
}