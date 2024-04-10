#include<iostream>

using namespace std;

int n , a , b;
const int max_n = 100 * 1000 + 30;

int main(){
    cin >> n >> a >> b;
    long long int temp;
    long long int t , tt;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 tt = temp * a;
	 t = tt / b;

	 t *= b;
	 t = tt - t;

	 if ( i != n - 1)	cout << t / a << " ";
	 else	  cout << t / a << endl;
    }
    return 0;
}