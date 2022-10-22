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

int n , m , ans , temp;

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++){
	     cin >> temp;
	     if (temp == 1 && (i == 0 || j == 0 || i == n - 1 || j == m - 1))	ans = 2;
	 }
    if (ans == 2)   cout << ans << endl;
    else    cout << 4 << endl;
    return 0;
}