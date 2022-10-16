#include<bits/stdc++.h>
using namespace std;
int T;
int main(){cin>>T;
	while(T--){
		long long a,b,c,d;
		cin>>b>>a>>c>>d;
		if(a>=b)cout<<a<<endl;
		else{
			if(c<=d){
				cout<<-1<<endl;
				continue;
			}
			if((b-a)%(c-d)==0)
				cout<<a+(b-a)/(c-d)*c;
			else
				cout<<a+(b-a)/(c-d)*c+c;
			cout<<endl;
		}
	}
}