#include<iostream>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;int d=b-a;
	if(c==0){
		if(d==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	if(c>0){
		if(d>=0 && d%c==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	if(c<0){
		if(d<=0 && (-d)%(-c)==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}