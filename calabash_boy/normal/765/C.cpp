#include<iostream>
using namespace std;
int main(){
	int k,m,n;
	cin>>k>>m>>n;
	if (m<k&&n<k) {cout<<"-1";return 0;}
	else if (n<k&&m%k!=0||m<k&&n%k!=0||n==0&&m==0) {cout<<"-1";return 0;}
	else cout<<n/k+m/k;
	return 0;
}