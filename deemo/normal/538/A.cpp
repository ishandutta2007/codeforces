#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<cstdio>
#include<iomanip>

using namespace std;

string s;
string p = "CODEFORCES";

int main(){
    cin >> s;
    string temp;

    for (int i = 0 ; i < s.size() ; i++)
	 for (int j = i ; j < s.size() ; j++){
	     temp = "";
	     for (int k = 0 ; k < i ; k++)
		  temp += s[k];
	     for (int k = j + 1 ; k < s.size() ; k++)
		  temp += s[k];
	     if (temp == p){
		  cout << "YES" << endl;
		  return 0;
	     }
	 }
    cout << "NO" << endl;

    return 0;
}