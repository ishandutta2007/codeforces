#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,x,y,z;
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x){
		cout<<"NO";
		return 0;
	}
	a-=x;
	if(y<=a){
		a-=y;
	}else{
		y-=a;
		a=0;
		if(b<y){
			cout<<"NO";
			return 0;
		}
		b-=y;
	}
	if(a+b+c<z){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}