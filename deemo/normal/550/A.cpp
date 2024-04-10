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

vector<int> sec , vec;

int main(){
    string s;
    cin >> s;
    for (int i = 0 ; i < s.size() - 1 ; i++){
	 if (s[i] == 'A' && s[i + 1] == 'B') vec.push_back(i);
	 if (s[i] == 'B' && s[i + 1] == 'A') sec.push_back(i);
    }
    if (vec.size() == 0 || sec.size() == 0){
	 cout << "NO" << endl;
	 return 0;
    }
    if (vec.size() > 1 || sec.size() > 1){
	 if (abs(vec[vec.size() - 1] - sec[sec.size() - 1]) == 1 && abs(vec[0] - sec[sec.size() - 1]) == 1
	 && abs(vec[vec.size() - 1] - sec[0] == 1) && abs(vec[0] - sec[0]) == 1){
	     cout << "NO" << endl;
	     return 0;
	 }
	 cout << "YES" << endl;
	 return 0;
    }
    if (abs(vec[0] - sec[0]) > 1)	 cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}