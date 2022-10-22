#include<bits/stdc++.h>
using namespace std;
int T;
int H,M;
int t,m;
int c[4];
bool ok(int x){return x==1||x==2||x==5||x==8||x==0;}
bool check(){
	c[0]=t/10,c[1]=t%10,c[2]=m/10,c[3]=m%10;
	for(int i=0;i<4;i++)if(!ok(c[i]))return 0;
	for(int i=0;i<4;i++)if(c[i]==2||c[i]==5)c[i]=7-c[i];
	int tt=c[3]*10+c[2],mm=c[1]*10+c[0];
	return tt<H&&mm<M; 
}
int main(){
	cin>>T;
	while(T--){
		cin>>H>>M;
		string buf;cin>>buf;
		t=(buf[0]-'0')*10+buf[1]-'0',m=(buf[3]-'0')*10+buf[4]-'0';
		while(1){
			if(check()){
				if(t<10)cout<<"0";
				cout<<t<<":";
				if(m<10)cout<<"0";
				cout<<m<<"\n";
				break;
			}
			m++;
			if(m==M)m=0,t++;
			if(t==H)t=0;
		}
	}
}