#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main(){

	long long int n;
	cin >> n;
	long long int ans = 0;

	if ( n % 2 == 0 )	ans = n / 2;
	else	ans = ( ( n - 1 ) / 2 ) - n;

	cout << ans << endl;

	return 0;

}