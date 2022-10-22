#include<iostream>
using namespace std;
int abs(int a){
	if(a<0)return -a;
	else return a;
}
int main(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		cout<<6+abs(y1-y2)*2<<endl;
		return 0;
	}
	if(y1==y2){
		cout<<6+abs(x1-x2)*2<<endl;
		return 0;
	}
	cout<<(abs(x1-x2)+abs(y1-y2))*2+4<<endl;
	return 0;
}