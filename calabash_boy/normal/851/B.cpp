#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dist(int x1,int y1,int x2,int y2){
	LL dx = x1-x2;
	LL dy = y1-y2;
	return dx*dx+dy*dy;
}
int main(){
	LL xa,xb,xc,ya,yb,yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	if (xb*2==xa+xc&&yb*2==ya+yc){
		cout<<"No"<<endl;
		return 0;
	}
	if (dist(xa,ya,xb,yb)==dist(xb,yb,xc,yc)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}