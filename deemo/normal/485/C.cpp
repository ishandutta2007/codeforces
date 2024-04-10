#include<iostream>
#include<vector>

using namespace std;

long long int a , b;
long long megh;
vector<int> vec;


void getbin(){

	if ( a == 0 ){

		vec.clear();
		vec.push_back(0);
		return;

	}
	long long int temp = a;
	vec.clear();
	vec.push_back(1);
	vector<int> tempvec;
	while ( temp > 1 ){

		tempvec.push_back( temp % 2 );
		temp = temp / 2;
	
	}

	for ( int i = tempvec.size() - 1 ; i >= 0 ; i-- )
		vec.push_back( tempvec[i] );
	

}


int fl;
void addmegh(){

	int flag = 0;
	for ( int i = vec.size() - 1 ; i >= 0 ; i-- )
	{
	
		if ( vec[i] == 0 ){
	
			vec[i] = 1;
			break;

		}
		flag++;

	}
	
	if ( flag == vec.size() )	vec.push_back(1);

	long long temp = 1;
	for ( int i = 0 ; i < flag ; i++ )
		temp = temp * 2;
	if ( megh + temp <= b )	 megh += temp;
	else fl = 1;

}


int main(){

	int n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){

		fl = 0;
		cin >> a >> b;
		megh = a;
		getbin();
		while ( fl == 0 )
			addmegh();
		cout << megh << endl;

	}

	return 0;

}