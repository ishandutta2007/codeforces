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

long long ans = 0;
int n , m;
char c[100][100];
int f[400];

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     cin >> c[i][j];
    for (int i = 0 ; i < n - 1 ; i ++)
	 for (int j = 0 ; j < m - 1 ; j++){
	     for (int k = 0 ; k < 200 ; k++)
		  f[k] = 0;
	     f[int(c[i][j])] += 1;
	     f[int(c[i][j + 1])] += 1;
	     f[int(c[i + 1][j])] += 1;
	     f[int(c[i + 1][j + 1])] += 1;
	     if (f[int('f')] && f[int('a')] && f[int('c')] && f[int('e')])   ans++;
	 }
    cout << ans << endl;
    return 0;
}