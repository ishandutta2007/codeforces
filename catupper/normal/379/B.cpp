#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	int a[315];
	cin >> n;
	for(int i = 0;i < n;i++)cin >> a[i];
	while(a[0]--){
		cout << "PRL";
	}
	for(int i = 1;i < n;i++){
		cout << 'R';
		while(a[i]--)cout << "PLR";
	}
	cout << endl;
	return 0;	
}