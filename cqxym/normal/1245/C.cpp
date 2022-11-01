#include<stdio.h>
#include<iostream>
using namespace std;
string s;
int f[100001];
const int p=1e9+7;
int main(){
	cin>>s;
	int n=s.length();
	if(s[1]=='m'||s[1]=='w'||s[0]=='m'||s[0]=='w'){
		printf("0");
		return 0;
	}
	f[0]=1;
	if(s[1]=='n'){
		if(s[0]=='n'){
			f[1]=2;
		}else{
			f[1]=1;
		}
	}else if(s[1]=='u'){
		if(s[0]=='u'){
			f[1]=2;
		}else{
			f[1]=1;
		}
	}else{
		f[1]=1;
	}
	for(register int i=2;i<=n;i++){
		if(s[i]=='m'||s[i]=='w'){
			printf("0");
			return 0;
		}
		if(s[i]=='n'){
			if(s[i-1]=='n'){
				f[i]=(f[i-1]+f[i-2])%p;
			}else{
				f[i]=f[i-1];
			}
		}else if(s[i]=='u'){
			if(s[i-1]=='u'){
				f[i]=(f[i-1]+f[i-2])%p;
			}else{
				f[i]=f[i-1];
			}
		}else{
			f[i]=f[i-1];
		}
	}
	printf("%d",f[n]);
	return 0;
}