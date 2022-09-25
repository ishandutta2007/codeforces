#include <iostream>
#include <cmath>

using namespace std;
int main(){
	int n;
	cin >> n;
	long long int a[n][n];
	long long int x;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int b[n];
	for(int i=0; i<n; i++){
		if(i==0){
			x=sqrt(a[0][1]*a[0][2]/a[1][2]);
			b[0]=x;
		}
		else if(i==1){
			x=sqrt(a[0][1]*a[1][2]/a[0][2]);
			b[1]=x;
		}
		else{
			x=sqrt(a[i][0]*a[i][1]/a[0][1]);
			b[i]=x;
		}
	}
	for(int i=0; i<n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}