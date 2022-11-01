#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstring>

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<LL,LL> pll;


int main(){
    int k;
    string s;
    cin >> k >> s;

    if( s.size() % k != 0 ){
        cout << "-1\n";
        return 0;
    }
    int a = s.size() / k;

    string ans(s.size(), '_');
    map<char,int> mp;
    map<char,int>::iterator it;
    for(int i = 0; i < s.size(); ++i){
        ++mp[s[i]];
    }

    it = mp.begin();
    int t = 0;
    for(int i = 0; it != mp.end(); ++it){
        if( it->second % k != 0 ){
            cout << "-1\n";
            return 0;
        }

        int z = it->second / k;
        for(int h = 0; h < z; ++h, ++t){
            for(int j = 0; j < k; ++j){
                ans[j * a + t] = it->first;
            }
        }
    }
    
    cout << ans << endl;
}