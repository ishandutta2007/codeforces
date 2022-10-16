#include<bits/stdc++.h>
using namespace std;
int bit[262145],n,m,x,y;
void change(int xx,int yy){
	xx+=pow(2,n)-2;
	bit[xx]=yy;
	bool cnt=0;
	while(xx>0){
		cnt^=1;
		xx=(xx-1)/2;
		if(cnt)bit[xx]=(bit[xx*2+1]|bit[xx*2+2]);
		else bit[xx]=(bit[xx*2+1]^bit[xx*2+2]);
	}
}
bool can(int x){
	int i;
	for(i=0;pow(2,i)-2<x;i++);
	if((n-i)%2)return 0;
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=pow(2,n)-1;i<pow(2,n+1)-1;i++)cin>>bit[i];
	for(int i=pow(2,n)-2;i>=0;i--)
		if(can(i))
			bit[i]=(bit[i*2+1]|bit[i*2+2]);
		else
			bit[i]=(bit[i*2+1]^bit[i*2+2]);
	//cout<<bit[0]<<endl;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		change(x,y);
		//for(int i=0;i<pow(2,n+1)-1;i++)cout<<bit[i]<<' ';
		cout<<bit[0]<<endl;
	}
}