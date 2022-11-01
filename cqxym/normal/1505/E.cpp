#include<iostream>
using namespace std;
#define R register int
string s[5];
inline int Dis(int a,int b,int c,int d){
	a-=c;
	b-=d;
	return(a<0?-a:a)+(b<0?-b:b);
}
int main(){
	int h,w,x=0,y=0;
	cin>>h>>w;
	for(R i=0;i!=h;i++){
		cin>>s[i];
	}
	int ans=s[0][0]=='*';
	while(x!=h-1||y!=w-1){
		int p=h-1,q=w-1;
		s[x][y]='.';
		for(R i=x;i!=h;i++){
			for(R j=y;j!=w;j++){
				if(s[i][j]=='*'&&Dis(i,j,x,y)<Dis(x,y,p,q)){
					p=i;
					q=j;
				}
			}
		}
		x=p;
		y=q;
		ans+=s[x][y]=='*';
	}
	cout<<ans;
	return 0;
}