#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b))
			cout<<-1<<endl;
		else
			cout<<(y-x)/(a+b)<<endl;
	}
}