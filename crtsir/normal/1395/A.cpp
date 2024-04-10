#include<bits/stdc++.h>
using namespace std;
int T,r,g,b,w;
int main(){
	cin>>T;
	while(T--){
		cin>>r>>g>>b>>w;
		if(r>0&&g>0&&b>0)
			if(r%2+g%2+b%2+w%2==2)
				cout<<"No\n";
			else
				cout<<"Yes\n";
		else
			if(r%2+g%2+b%2+w%2<2)
				cout<<"Yes\n";
			else
				cout<<"No\n";
	}
}