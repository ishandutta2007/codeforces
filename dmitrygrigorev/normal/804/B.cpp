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
string s;
int CONST = 1000000007;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> s;
    int b = 0;
    int ans = 0;
    for (int i=s.size()-1;i>=0;i--){
        if (s[i] == 'b') b++;
        else{
            ans += b;
            ans %= CONST;
            b *= 2;
            b %= CONST;
        }
    }
    ans += CONST;
    ans %= CONST;
    cout << ans << endl;
    return 0;
}