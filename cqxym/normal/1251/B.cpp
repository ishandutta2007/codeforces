#include<stdio.h>
#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,ct=0,cnt=0,l;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		string s;
		cin>>s;
		l=s.length();
		for(R j=0;j<l;j++){
			if(s[j]=='1'){
				ct++;
			}
		}
		if(l%2==1){
			cnt=1;
		}
	}
	if(ct%2==1&&cnt==0){
		printf("%d\n",n-1);
	}else{
		printf("%d\n",n);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}