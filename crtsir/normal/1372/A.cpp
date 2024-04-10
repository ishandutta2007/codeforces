#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cout<<(i/2)*2+1<<' ';
		cout<<endl;
	}
}