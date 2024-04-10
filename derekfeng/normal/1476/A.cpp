#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(n==k)puts("1");
		else if(n>k) printf("%d\n",2-(n%k==0));
		else if(n<k) printf("%d\n",(k+n-1)/n);
	}
}