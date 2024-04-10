#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string ansmax;
string ansmin;
int m , s;
int flag1;
int flag2;


int saghf( int a , int b ){

	if ( a % b == 0 )	return a / b;
	else return a / b + 1;

}


int maxi( int mm , int ss ){

	if ( ss == 0 )	return 0;
	for ( int i = 9 ; i >= 1 ; i-- ){

		if ( i <= ss ) return i;

	}

	return 0;

}


int mini( int mm , int 	ss ){

	if ( mm == 1 )	return ss;
	for ( int i = 0 ; i <= 9 ; i++ ){

		if ( ( saghf ( ss - i , 9 ) <= mm - 1 ) )	
			if ( ( mm != m ) || ( i != 0 ) )	return i;

	}
	
	return 0;

}


void getMax(){

	int mm = m;
	int ss = s;
	int temp;
	for ( int i = mm ; i >= 1 ; i-- ){

		temp = maxi( mm , ss );	
		ansmax += temp + 48;	
		ss -= temp;
		mm--;

	}


}


void getMin(){

	int mm = m;
	int ss = s;
	int temp;
	for ( int i = mm ; i >= 1 ; i-- ){

		temp = mini( mm , ss );
		ansmin += temp + 48;
		ss -= temp;
		mm--;

	}

}


int main(){

	cin >> m >> s;	
	getMax();
	getMin();
	
	if ( ( m > 1 ) && ( s == 0 ) )	flag1 = 1;
	if ( saghf( s , 9 ) > m )	flag1 = 1;
	if ( ( m == 1 ) && ( s == 0 ) ){

		flag1 = 0;
		ansmin = "0";
		ansmax = "0";

	}
	
	
	if ( flag1 == 1 ) cout << "-1 -1" << endl;
	else{
		 cout << ansmin << " ";
		cout << ansmax << endl; 
	}

	return 0;

}