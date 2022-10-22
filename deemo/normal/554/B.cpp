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

int n , cnt , ans;
char c[200][200] , b[200][200];

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < n ; j++)
	     cin >> c[i][j];
    for (int i = 0 ; i < n ; i++){
	 cnt = 0;
	 for (int j = 0 ; j < n ; j++)
	     for (int k = 0 ; k < n ; k++)
		  b[j][k] = c[j][k];
	 for (int j = 0 ; j < n ; j++)
	     if (b[i][j] == '0')
		  for (int k = 0 ; k < n ; k++){
		      if (b[k][j] == '1') b[k][j] = '0';
		      else	b[k][j] = '1';
		  }
	 for (int j = 0 ; j < n ; j++){
	     int flag = 0;
	     for (int k = 0 ; k < n ; k++)
		  if (b[j][k] == '0') flag = 1;
	     if (flag == 0)	cnt++;
	 }
	 ans = max(ans , cnt);
    }
    cout << ans << endl;
    return 0;
}