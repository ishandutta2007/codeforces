#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n < 4) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		for(int i = n;i > 5;i -= 2){
			cout<<i<<" - "<<i-1<<" = 1"<<endl;
			cout<<"1 * 1 = 1"<<endl;
		}
		if(n%2 == 1){
			cout<<"5 - 1 = 4"<<endl;
			cout<<"4 - 2 = 2"<<endl;
		}
		else {
			cout<<"2 * 1 = 2"<<endl;
		}
		cout<<"2 * 3 = 6"<<endl;
		cout<<"6 * 4 = 24"<<endl;
	}
}