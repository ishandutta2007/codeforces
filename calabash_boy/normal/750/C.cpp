#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int c,d;
	int delta=0;
	int ans=-1900000;
	int max=190000000,min=-2147483645;
	for (int i=1;i<=n;i++){
		cin>>c>>d;
		if (d==1) min=min>1900-delta?min:1900-delta;
		if (d==2) max=max<1900-delta?max:1900-delta;
		if (min>=max){
			cout<<"Impossible";
			return 0;
		}else {delta+=c;}
	}
	if (max==190000000){
		cout<<"Infinity";
		return 0;
	}
	cout<<max-1+delta;	
	return 0;
}