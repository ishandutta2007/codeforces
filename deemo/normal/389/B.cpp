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

int n;
char jad[200][200];
int flag;

int main(){
    cin >> n;
    for (int i = 0 ; i <= n + 1 ; i++)
	 for (int j = 1 ; j <= n + 1 ; j++){
	     if (i == 0 || i == n + 1)   jad[i][j] = '.';
	     else if (j == n + 1 || j == 0) jad[i][j] = '.';
	     else cin >> jad[i][j];
	 }    

    for (int i = 1 ; i <= n ; i++){
	 for (int j = 1 ; j <= n ; j++)
	     if (jad[i][j] == '#'){
		  jad[i][j] = '.';
		  if (jad[i + 1][j] == '.')	  flag = 1;
		  if (flag == 1)  break;
		  if (jad[i + 1][j - 1] == '.')   flag = 1;
		  if (flag == 1)  break;
		  if (jad[i + 1][j + 1] == '.')   flag = 1;
		  if (flag == 1)  break;
		  if (jad[i + 2][j] == '.')	  flag = 1;
		  if (flag == 1)  break;
		  jad[i + 1][j] = '.';
		  jad[i + 1][j - 1] = '.';
		  jad[i + 1][j + 1] = '.';
		  jad[i + 2][j] = '.';
		  jad[i][j] = '.';
	     }
	 if (flag == 1)  break;
    }
    if ( flag == 1) cout << "NO" << endl;
    else    cout << "YES" << endl;
    return 0;
}