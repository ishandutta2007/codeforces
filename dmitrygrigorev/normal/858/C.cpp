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
using namespace std;
bool sogl(char ch){
    if (ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e') return false;
    return true;
}
bool r(char c1, char c2, char c3){
    if (c1 == c2 && c1 == c3) return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string ans = "";
    int fl = 0;
    for (int i=0; i < s.size(); i++){
        if (i < 2){
            ans += s[i];
        }
        else{
            if (sogl(s[i-1]) && sogl(s[i-2]) && sogl(s[i]) && !r(s[i-2], s[i-1], s[i]) && fl <= i-2){
                fl = i;
                ans += " ";
                ans += s[i];
            }
            else{
                ans += s[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}