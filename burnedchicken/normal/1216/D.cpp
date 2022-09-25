#include <iostream>

using namespace std;

int main(){
	int n,v;
	long long int x,Max,Min,index1,index2;
	cin >> n;
	long long int a[n],b[n];
	v=INT_MIN;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i]>v) v=a[i];
	}
	for(int i=0; i<n; i++){
		b[i]=v-a[i];
	}
	while(1){
		Max=INT_MIN;
		Min=INT_MAX;
		for(int i=0; i<n; i++){
			if(b[i]>Max){
				Max=b[i];
			}
			if(b[i]<Min&&b[i]>0){
				Min=b[i];
			}
		}
		if(Max==Min) break;
		index1=index2=-1;
		for(int i=0; i<n; i++){
			if(index1==-1&&b[i]!=0) index1=i;
			else if(b[i]!=0) index2=i;
			if(index2>=0){
				if(b[index1]>b[index2]) b[index1]=b[index1]%b[index2];
				else b[index2]=b[index2]%b[index1];
				index1=index2=-1;
			}
		}
	}
	x=0;
	for(int i=0; i<n; i++){
		x=x+(v-a[i])/Max;
	}
	cout << x << " " << Max << endl;
	return 0;
}