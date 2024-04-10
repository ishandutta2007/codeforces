#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int a[2][2];
		cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
		if(a[0][0]&&a[1][1]&&a[1][0]&&a[0][1]){
			cout<<2<<endl;
			continue;
		}
		if(a[0][0]||a[0][1]||a[1][0]||a[1][1]){
			cout<<1<<endl;
			continue;
		}cout<<0<<endl;
	}
}