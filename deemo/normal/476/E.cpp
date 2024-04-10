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

string s1 , s2;
int d[3000];
int dp[3000][3000];

int main(){
    cin >> s1 >> s2;
    for (int i = 0 ; i < s1.size() ; i++){
	 int t = i;
	 for (int j = s2.size() - 1 ; j >= 0 ; j--){
	     while(t >= 0 && s1[t] != s2[j])	 t--;
	     t--;   
	     if (t == -1 && j != 0)	 t = -10;
	     if (t < 0)  break;
	 }
	 if (t < -1) t = -2;
	 d[i] = t + 1;
    }
    //dp[a][b] -> ba hazfe a ta char, stringe b taEye avval chand ta pattern dareh
    for (int i = 0 ; i < s1.size() ; i++)
	 for (int j = 0 ; j < s1.size() ; j++){
	     if (i + s2.size() > j + 1)  continue;
	     if (i == 0){
		  if (d[j] != -1 && d[j] == j - s2.size() + 1){
		      if (j == s2.size() - 1) dp[i][j] = 1;
		      else	dp[i][j] = 1 + dp[i][j - s2.size()];
		  }
		  else{
		      if (j == 0) dp[i][j] = 0;
		      else	dp[i][j] = dp[i][j - 1];
		  }   
	     }
	     
	     else    if (j == 0){
		  if (i != 0)	dp[i][j] = 0;
		  else	   if (s2.size() == 0 && s2[0] == s1[j])	dp[i][j] = 1;
		  else	   dp[i][j] = 0;
	     }	  

	     else{
		  if (s1[j] != s2[s2.size() - 1]) dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j - 1]);
		  else{
		      //khodesh nayad:
		      int t = max(dp[i - 1][j - 1] , dp[i][j - 1]);
		      //khodesh biad hatman:
		      int temp = 0 , g = j - d[j] + 1 - s2.size();//g: chand ta bayad hazf konim ta akhari ok she
		      if (d[j] == -1) temp = 0;
		      else	if (g > i)	temp = 0;
		      else	temp = 1 + dp[i - g][d[j] - 1];
		      //max:
		      dp[i][j] = max(temp , t); 
		  }
	     }
	 }
    for (int i = 0 ; i < s1.size() ; i++)
	 cout << dp[i][s1.size() - 1] << " ";
    cout << 0 << endl;
    return 0;
}