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

string s;
int cnt , flag;

int main(){
    cin >> s;

    for (int i = 0 ; i < s.size() ; i++){
	 if (s[i] < 'a') cnt++;
	 if (i == 0 && s[i] >= 'a')	 flag = 1;
    }
    
    if (cnt == s.size() || (flag == 1 && cnt == s.size() - 1)){
	 for (int i = 0 ; i < s.size() ; i++){
	     if (s[i] < 'a')	s[i] = s[i] + 32;
	     else    s[i] = s[i] - 32;
	 }
    }

    cout << s << endl;

    return 0;
}