#include<bits/stdc++.h>

using namespace std;

char x[1000];

int main(){
	cin>>x;
	int n=strlen(x);
	for(int i=1;i<=n;i++){
		if(i%2){
			cout<<x[(n+1)/2-(i)/2-1];
		}else{
			cout<<x[(n+1)/2+(i)/2-1];
		}
	}
	return 0;
}