#include <iostream>

using namespace std;

int main(){
	int n,x,y;
	cin >> n;
	int a[n],b[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		b[i]=i+1;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i]>=a[j]){
				x=a[i];
				y=b[i];
				for(int k=i; k>j; k--){
					a[k]=a[k-1];
					b[k]=b[k-1];
				}
				a[j]=x;
				b[j]=y;
				break;
			}
		}
	}
	x=0;
	for(int i=0; i<n; i++){
		x=x+a[i]*i+1;
	}
	cout << x << endl;
	for(int i=0; i<n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}