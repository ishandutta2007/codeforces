#include<iostream>
using namespace std;
int main(){
	long long now,ans;
	cin>>now;
	if (now==1){
		cout<<1<<endl;
		return 0;
	}
	long long temp = 1;
	while (temp<=now){
		temp*=10;
	}
	temp/=10;
	ans = (now/temp+1)*temp;
	cout<<ans-now<<endl;
	return 0;
}