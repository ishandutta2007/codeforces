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

vector<string>  ans;

int main(){ 
    string s;
    cin >> s;
    string temp = "";

    while (1){
	 int flag = 0;
	 temp = "";
	 for (int i = 0 ; i < s.size() ; i++){
	     if (s[i] != '0')    flag = 1;
	     if (flag == 1){
		  if (s[i] != '0'){
		      s[i] -= 1;
		      temp += '1';
		  }
		  else	   temp += '0';
	     }
	 } 
	 if (flag == 0)  break;
	 ans.push_back(temp);
    }

    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() - 1 ; i++)
	 cout << ans[i] << " ";
    cout << ans[ans.size() - 1] << endl;

    return 0;
}