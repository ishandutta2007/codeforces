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
#include <queue>
#include <ctime>
#define int long long
using namespace std;
int32_t main(){
    string s;
    int k;
    cin >> s >> k;
    set<char> ms;
    for (int i=0; i < s.size(); i++){
        ms.insert(s[i]);
    }
    if (s.size() < k){
        cout << "impossible" << endl;
    }
    else cout << max((int) 0, k - ms.size()) << endl;
}