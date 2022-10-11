#include<iostream>
using namespace std;
int n,m,d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	cin>>n>>m;m--;int p=m+d[n]-1;
	cout<<(p/7)-(m/7)+1<<endl;
	return 0;
}