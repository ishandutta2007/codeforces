#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		int x,y=0,z=0;cin>>x;
		while(x%3==0)y++,x/=3;
		while(x%2==0)z++,x/=2;
		if(x!=1)cout<<-1<<endl;
		else if(y<z)cout<<-1<<endl;
		else cout<<y*2-z<<endl;
	}
}