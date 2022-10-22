#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
string s;
int p;
int n;
int arr[100 * 1000];


int getd( int i ){

	char c1 , c2;
	c1 = s[i];
	c2 = s[n - 1 - i];
	if ( c1 > c2 ){
	
		char temp = c1;
		c1 = c2;
		c2 = temp;

	}

	return min( ( c2 - c1 ) , ( c1 - 97 ) + ( 123 - c2 ) );
	

}


int x = 0;
int ans = 0;
int main(){
	cin >> n >> p;
	p--;
	cin >> s;

	int t1 , t2;
	t1 = 0;
	t2 = ( n / 2 ) - 1;
	if ( p > t2 ){

		t1 = t2 + 1;
		t2 = n - 1;

	}
	int mini = n + 10 , maxi = -10;
	for ( int i = t1 ; i <= t2 ; i++ ){

		if ( s[i] != s[ n - 1 - i ] ){
			if ( i < mini )	mini = i;
			if ( i > maxi ) maxi = i;
			arr[i] = getd(i);
			ans += arr[i];

		}

	}
	if ( ans == 0 )	cout << 0 << endl;
	else{
		if ( ( mini <= p ) && ( maxi >= p ) ){

			if ( p - mini <= maxi - p ) ans += 2 * (p - mini ) + (maxi - p);
			else ans += 2 * ( maxi - p ) + (p - mini);
	
		}
		else{

			ans += max( abs( maxi - p ) , abs( mini - p ) );

		}

		cout << ans << endl;
	}
	


	return 0;

}