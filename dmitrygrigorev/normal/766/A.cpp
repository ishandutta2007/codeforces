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
using namespace std;
string s1, s2;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    if (s1 == s2) cout << -1 << endl;
    else cout << max(s1.size(), s2.size()) << endl;
    return 0;
}