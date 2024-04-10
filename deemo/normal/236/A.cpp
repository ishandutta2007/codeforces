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
bool mark[300];

int main(){
    string s;
    cin >> s;

    for (int i = 0 ; i < s.size() ; i++)
	 mark[s[i]] = 1;

    for (int i = 'a' ; i <= 'z' ; i++)
	 if (mark[i] == 1)    ans++;
    
    if (ans % 2 == 0)   cout << "CHAT WITH HER!" << endl;
    else    cout << "IGNORE HIM!" << endl;
    return 0;
}