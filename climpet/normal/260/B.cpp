#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


#define MOD 1000000009LL
#define EPS 1e-8


int main(){
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s;
    cin >> s;

    map<string,int> mp;

    for(int i = 0; i + 9 < s.size(); ++i){
        if(
            s[i+2] == '-' &&
            s[i+5] == '-' &&
            isdigit(s[i]) &&
            isdigit(s[i+1]) &&
            isdigit(s[i+3]) &&
            isdigit(s[i+4]) &&
            isdigit(s[i+6]) &&
            isdigit(s[i+7]) &&
            isdigit(s[i+8]) &&
            isdigit(s[i+9])
        ){
            int d = strtol(s.c_str() + i, 0, 10);
            int m = strtol(s.c_str() + (i + 3), 0, 10);
            int y = strtol(s.substr(i + 6, 4).c_str(), 0, 10);

            if(y >= 2013 && y <= 2015 && m > 0 && m <= 12 && d > 0 && d <= days[m]){
                ++mp[s.substr(i, 10)];
            }
        }
    }

    map<string,int>::iterator it, it2;
    for(it = it2 = mp.begin(); it != mp.end(); ++it){
        if(it->second > it2->second){
            it2 = it;
        }
    }
    
    cout << it2->first << endl;
}