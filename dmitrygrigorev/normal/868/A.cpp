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
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    int b = 0, c = 0;
    bool yes = false;
    for (int i=0; i < n; i++){
        string s1;
        cin >> s1;
        if (s1 == s){
            cout << "YES" << endl;
            return 0;
        }
        if (s1[0] == s[1]) b++;
        if (s[0] == s1[1]) c++;
    }
    if (b == 0 || c == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}