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

long long n , m , b , mod , first , second;
const int max_n = 505;
int arr[max_n];
long long d[2][max_n][max_n];

void init(){
    first = 0;
    second = 1;

    for (int j = 0 ; j <= m ; j++){
	 for (int k = 0 ; k <= b ; k++){
	     if (j * arr[1] <= k)	 d[first][j][k] = 1;
	     else    d[first][j][k] = 0;
	     d[first][j][k] %= mod;
	 }
    }

    first = 1;
    second = 0;
}

int main(){
    cin >> n >> m >> b >> mod;
    for (int i = 1 ; i <= n ; i++)
	 cin >> arr[i];

    init();

    for (int i = 2 ; i <= n ; i++){
	 for (int j = 0 ; j <= m ; j++){
	     for (int k = 0 ; k <= b ; k++){
		  d[first][j][k] = 0;

		  if (j == 0){
		      d[first][j][k] = 1;
		      continue;
		  }

		  if (k - arr[i] >= 0)
		      d[first][j][k] = d[first][j - 1][k - arr[i]];
		  d[first][j][k] += d[second][j][k];
		  d[first][j][k] %= mod;
	     }
	 }


	 if (i % 2 == 0) first = 0;
	 else	  first = 1;
	 if (i % 2 == 0) second = 1;
	 else	  second = 0;	
    }    

    cout << d[second][m][b] << endl;

    return 0;
}