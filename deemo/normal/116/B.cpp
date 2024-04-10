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

int n , m , ans;
char jad[100][100];

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     cin >> jad[i][j];
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     if (jad[i][j] == 'P'){
		  jad[i][j] = '.';
		  if (i + 1 < n && jad[i + 1][j] == 'W'){
		      jad[i+1][j] = '.';
		      ans++;
		      continue;
		  }
		  if (i - 1 >= 0 && jad[i - 1][j] == 'W'){
		      jad[i-1][j] = '.';
		      ans++;
		      continue;
		  }
		  if (j + 1 < m && jad[i][j + 1] == 'W'){
		      jad[i][j + 1] = '.';
		      ans++;
		      continue;
		  }
		  if (j - 1 >= 0 && jad[i][j - 1] == 'W'){
		      jad[i][j - 1] = '.';
		      ans++;
		      continue;
		  }
	     }	  
    cout << ans << endl;
    return 0;
}