#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>

using namespace std;

long long int a;


bool is_bad( long long int x ){

	x = abs(x);
	while ( x > 0 ){

		if ( x % 10 == 8 )	return false;
		x = x / 10;

	}

	return true;

}


int main(){

	cin >> a;
	int flag = 0;
	while ( ( is_bad(a) ) || ( flag == 0 ) ){

		a++;
		flag++;

	}

	cout << flag << endl;
	return 0;

}