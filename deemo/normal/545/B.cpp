#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

int cnt;

int main(){
    string s , t;
    cin >> s >> t;
    for (int i = 0 ; i < s.size() ; i++)
	 if (s[i] != t[i])	cnt++;
    if (cnt % 2 != 0){
	 cout << "impossible" << endl;
	 return 0;
    }
    string ans = s;
    int j = 0;
    for (int i = 0 ; i < s.size() ; i++){
	 if (j == cnt / 2)	break;
	 if (s[i] == t[i])	continue;
	 ans[i] = t[i];
	 j++;
    }
    cout << ans << endl;
    return 0;
}