#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y;
		if(y%x==0)
			cout<<1<<' '<<y/x<<endl;
		else
			cout<<"0 0\n";
	}
}