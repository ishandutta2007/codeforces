#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
string s;
int a[300001],b[300001];
inline void Solve(){
	cin>>s;
	int l=s.length(),l1=0,l2=0,x,y;
	for(R i=0;i<l;i++){
		x=s[i]^48;
		if((x&1)>0){
			a[l1]=x;
			l1++;
		}else{
			b[l2]=x;
			l2++;
		}
	}
	x=0;
	y=0;
	while(x<l1&&y<l2){
		if(a[x]<b[y]){
			printf("%d",a[x]);
			x++;
		}else{
			printf("%d",b[y]);
			y++;
		}
	}
	while(x<l1){
		printf("%d",a[x]);
		x++;
	}
	while(y<l2){
		printf("%d",b[y]);
		y++;
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}