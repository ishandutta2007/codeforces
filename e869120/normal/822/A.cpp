#include<bits/stdc++.h>
using namespace std;
long A,B,C=1;
int main(){
	cin>>A>>B;
	for(int i=1;i<=min(A,B);i++)C*=i;
	cout<<C<<endl;
	return 0;
}