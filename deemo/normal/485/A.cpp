#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int max_size = 100 * 1000;
long long int a;
int m;
int arr[ max_size + 10 ];

int main(){

	cin >> a >> m;

	while ( a < m ){
		a += a % m;
	}

	int f = 2;
	while ( ( arr[f] < 2 ) && ( f > 0 ) ){
	
		f = a % m;
		arr[f] += 1;
		a = ( a + f ) % m;

	} 

	if ( f == 0 )	cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}