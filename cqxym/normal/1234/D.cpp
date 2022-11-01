#include<stdio.h>
#include<iostream>
using namespace std;
#define R register int
int c[26][100001],l;
void Add(int a,int x,int f){
	for(int i=x;i<=l;i+=i&-i){
		c[a][i]+=f;
	}
}
int Get(int a,int x){
	int s=0,i;
	for(i=x;i>0;i-=i&-i){
		s+=c[a][i];
	}
	return s;
}
int Ans(int x,int y){
	int s=0;
	for(R i=0;i<26;i++){
		if(Get(i,y)-Get(i,x-1)>0){
			s++;
		}
	}
	return s;
}
string s;
int main(){
	cin>>s;
	int q,a,b;
	l=s.length();
	scanf("%d",&q);
	for(R i=0;i<l;i++){
		Add(s[i]-97,i+1,1);
	}
	char z;
	for(R i=0;i<q;i++){
		scanf("%d%d ",&a,&b);
		if(a==1){
			z=getchar();
			Add(s[b-1]-97,b,-1);
			Add(z-97,b,1);
			s[b-1]=z;
		}else{
			scanf("%d",&a);
			printf("%d\n",Ans(b,a));
		}
	}
	return 0;
}