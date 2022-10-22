#include<iostream>

using namespace std;


int main(){
	int n , t = 1;
	cin >> n;
	int cur_height = 0;
	while ( n >= t ){
		cur_height += 1;
		n -= t;
		t += cur_height + 1;

	}
	cout << cur_height << endl;
	return 0;

}