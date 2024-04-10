#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	char a[n];
	int x=0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i]=='n') x++;
	}
	int y=(n-x*3)/4;
	for(int i=0; i<x; i++){
		cout << 1 << " ";
	}
	for(int i=0; i<y; i++){
		cout << 0 << " ";
	}
	cout << endl;
	return 0;
}