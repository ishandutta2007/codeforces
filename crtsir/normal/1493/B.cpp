#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	if(x==0)return 1;
	if(x==1)return 1;
	if(x==2)return 1;
	if(x==3)return 0;
	if(x==4)return 0;
	if(x==5)return 1;
	if(x==6)return 0;
	if(x==7)return 0;
	if(x==8)return 1;
	if(x==9)return 0;
}
int ok(int x){
	if(x==0)return 0;
	if(x==1)return 1;
	if(x==2)return 5;
	if(x==5)return 2;
	if(x==8)return 8;
}
int main(){
	int T,h,m,hh,mm;
	cin>>T;
	while(T--){
		scanf("%d%d",&h,&m);
		scanf("%d:%d",&hh,&mm);
		for(int i=0;i<h*m;i++){
			int H=((hh*m+mm+i)/m)%h,M=(mm+i)%m;
			if(!check(H/10)||!check(H%10)||!check(M/10)||!check(M%10))continue;
			int MM=ok(H%10)*10+ok(H/10),HH=ok(M%10)*10+ok(M/10);
			if(HH<h&&MM<m){
//				cout<<H<<' '<<M<<' '<<HH<<' '<<MM<<endl;
				cout<<H/10<<H%10<<':'<<M/10<<M%10<<endl;
				break;
			}
		}
	}
}