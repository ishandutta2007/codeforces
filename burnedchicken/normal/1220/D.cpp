#include <iostream>

using namespace std;

int v2(long long int t){
	for(int i=0; i>=0; i++){
		if(t%2==1) return i;
		t=t/2;
	}
}

int main(){
	int n;
	cin >> n;
	long long int a[n];
	int b[70];
	int Max=INT_MIN;
	int maxindex;
	for(int i=0; i<70; i++){
		b[i]=0;
	}
	for(int i=0; i<n; i++){
		cin >> a[i];
		b[v2(a[i])]++;
	}
	for(int i=0; i<70; i++){
		if(b[i]>Max){
			Max=b[i];
			maxindex=i;
		}
	}
	cout << n-Max << endl;
	for(int i=0; i<n; i++){
		if(v2(a[i])!=maxindex){
			cout << a[i] << " ";
		}
	}
	cout << endl;
	return 0;
}