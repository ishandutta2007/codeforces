#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	cout<<n+m-1<<endl;
	for(int k=2;k<=m;k++)cout<<"1 "<<k<<endl;
	for(int k=1;k<=n;k++)cout<<k<<" 1"<<endl;
}