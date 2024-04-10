#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)

int n;
int a[2] , b[2] , c[2];

int main(){
	cin >> n;
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];
	if((b[0] > a[0]) == (c[0] > a[0]));
	else return cout << "NO" << endl , 0;
	if((b[1] > a[1]) == (c[1] > a[1]));
	else return cout << "NO" << endl , 0;
	cout << "YES" << endl;
	return 0;
}