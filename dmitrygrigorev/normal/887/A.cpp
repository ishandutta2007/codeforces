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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int fo = -1;
    for (int i=0; i < s.size(); i++){
        if (s[i] == '1'){
            fo = i;
            break;
        }
    }
    if (fo == -1){
        cout << "no" << endl;
        return 0;
    }
    int zos = 0;
    for (int i=fo+1; i < s.size(); i++){
        if (s[i] == '0') zos++;
    }
    if (zos >= 6) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}