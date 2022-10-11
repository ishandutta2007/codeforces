#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	cin>>n>>k;
	long long E=n/2;E=(E/(k+1))*(k+1);
	long long F=E/(k+1);
	cout<<F<<' '<<E-F<<' '<<n-E<<endl;
	return 0;
}