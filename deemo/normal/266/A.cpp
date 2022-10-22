#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	char last = '2';
	int ans = 0 ;
	while (n--){
		char temp;	cin >> temp;
		if (temp == last)	ans++;
		last = temp;
	}
	cout << ans << endl;
	return 0;
}