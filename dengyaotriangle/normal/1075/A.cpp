#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,x,y;
	cin>>n>>x>>y;
	long long dx0,dx1,dy0,dy1;
	dx0=x-1;
	dy0=y-1;
	dx1=n-x;
	dy1=n-y;
	long long dis1,dis2;
	dis1=dx0;
	if(dy0>dis1) dis1=dy0;
	dis2=dx1;
	if(dy1>dis2) dis2=dy1;
	if(dis1==dis2) cout<<"White";
	else if(dis1<dis2) cout<<"White";
	else cout<<"Black";
	return 0;
}