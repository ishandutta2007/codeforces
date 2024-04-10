#include<iostream>
using namespace std;
int main(){
	long long x,y,a;
	cin>>x>>y>>a;
	cout<<(x+a-1)/a*((y+a-1)/a);
	return 0;
}
/*1
6 6 4
*/