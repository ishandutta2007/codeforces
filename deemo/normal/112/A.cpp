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

int ans;

int main(){
    string s1 , s2;
    cin >> s1 >> s2;

    for (int i = 0 ; i < s1.size() ; i++){
	 if (s1[i] == s2[i] + 32 || s2[i] == s1[i] + 32)	continue;
	 if (s1[i] == s2[i])	continue;
	 
	 if (s1[i] >= 'a')	s1[i] -= 32;
	 if (s2[i] >= 'a')	s2[i] -= 32;

	 if (s1[i] < s2[i]){
	     ans = -1;
	     break;
	 }
	 ans = 1;
	 break;
    }	 
    cout << ans << endl;

    return 0;
}