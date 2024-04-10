#include<iostream>
using namespace std;
char a,b;
int main(){
	cin>>a>>b;int c=0;
	if(a=='a' || a=='h')c++;
	if(b=='1' || b=='8')c++;
	if(c==0)cout<<"8"<<endl;
	if(c==1)cout<<"5"<<endl;
	if(c==2)cout<<"3"<<endl;
	return 0;
}