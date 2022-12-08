#include<bits/stdc++.h>
using namespace std;
bool a[100];
int main() {
	int n;
	cin>>n;
	a[1]=a[7]=a[9]=1;
	if((a[n%10] || n>9 && n < 30 || a[n/10] ) && n!=12 ) cout<<"No"<<endl;//NO
	else cout<<"Yes"<<endl;
	return 0;
}