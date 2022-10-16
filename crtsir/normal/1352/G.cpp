#include<bits/stdc++.h>
using namespace std;
int n,T; 
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){cout<<1<<endl;continue;}
		if(n<4){cout<<-1<<endl;continue;}
		if(n>=5){
			for(int i=(int(n-1)/2)*2+1;i>=1;i-=2)
				if(i!=5)
					cout<<i<<' ';
			cout<<5<<' ';
			for(int i=2;i<=n;i+=2)
				cout<<i<<' ';
			cout<<endl;
		}else
			cout<<3<<' '<<1<<' '<<4<<' '<<2<<endl;
	} 
}