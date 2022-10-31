#include<iostream>
using namespace std;
int main(){
	int m,n,k;
	cin>>n>>m>>k;
	int tmp=k/(2*m);
	k%=(2*m);
	tmp+=(k?1:0);
	cout<<tmp<<' ';
	if (!k) k=2*m;
	tmp=k/2;
	k%=2;
	tmp+=(k?1:0);
	cout<<tmp<<' '<<(k?'L':'R');
	return 0;
}