#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if ((n&1)==0){
		n=n/2;
		cout<<n<<endl;
		for (int i=1;i<=n-1;i++){
			cout<<"2 ";
		}
		cout<<"2"<<endl;
	}else{
		n-=3;
		n/=2;
		cout<<n+1<<endl;
		for (int i=1;i<=n;i++){
			cout<<"2 "; 
		}
		cout<<3<<endl;
	}
	return 0;
}