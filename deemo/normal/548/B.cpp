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

bool a[600][600];
int g[1000];
int b , c;

int main(){
    int n , m, q;
    cin >> n >> m >> q;
    for (int i = 0 ; i < n ; i++){
	 int cnt = 0 , maxi = 0;
	 for (int j = 0 ; j < m ; j++){
	     cin >> a[i][j];
	     if (a[i][j] == 1)   cnt++;
	     else    cnt = 0;
	     maxi = max(cnt , maxi);   
	 }
	 g[i] = maxi;
    }

    for (int i = 0 ; i < q ; i++){
	 cin >> b >> c;  b--;    c--;
	 a[b][c] = !a[b][c];
	 int cnt = 0 , maxi = 0;
	 for (int j = 0 ; j < m ; j++){
	     if (a[b][j] == 1)   cnt++;
	     else    cnt = 0;
	     maxi = max(cnt , maxi);
	 }
	 g[b] = maxi;
	 for (int j = 0 ; j < n ; j++)
	     maxi = max(maxi , g[j]);
	 cout << maxi << endl;
    }

    return 0;
}