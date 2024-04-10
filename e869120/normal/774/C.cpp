#include<iostream>
using namespace std;
int main(){
	int n;cin>>n;
	int c=0;if(n%2==1){c=1;cout<<"7";}
	for(int i=c;i<n/2;i++)cout<<"1";cout<<endl;
	return 0;
}