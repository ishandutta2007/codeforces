#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	int ans = n/5;
	if (n % 5)	ans++;
	cout << ans << endl;
	return	0;	
}