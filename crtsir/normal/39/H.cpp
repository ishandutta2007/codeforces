#include<bits/stdc++.h>
using namespace std;
int n;
int nn(int x){
	if(x==0)return 0;
	return nn(x/n)*10+x%n;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++)
			cout<<nn(i*j)<<' ';
		cout<<endl;
	}
}