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

int r , g;
const int max_r = 2 * 1e5 + 20;
long long d[2][max_r];
const int q = 1e9 + 7;
const int max_h = 1000;
long long ans;

int main(){
    cin >> r >> g;
    if (r > 0)  d[0][1] = 1;
    if (g > 0)  d[0][0] = 1;
    int first = 1 , second = 0;

    for (int i = 2 ; i <= max_h ; i++){
	 int blocks = (i * (i + 1)) / 2 , fl = 0;
	 for (int j = 0 ; j <= r ; j++){//ba daghighan j ta red, chand ta tower be toole i mishe sakht?
	     d[first][j] = 0;
	     if (j + g < blocks)    continue;
	     if (j >= i) d[first][j] = d[second][j - i];
	     if (g >= i) d[first][j] += d[second][j];
	     if (d[first][j] > 0)   fl = 1;
	     d[first][j] %= q;
	 }
	 
	 if (fl == 0){
	     for (int j = 0 ; j <= r ; j++)
		  ans = (ans + d[second][j]) % q;
	     break;
	 }

	 if (i % 2 == 0){
	     first = 0;
	     second = 1;
	 }
	 else{
	     first = 1;
	     second = 0;
	 }
    }
    cout << ans << endl;
    
    return 0;
}