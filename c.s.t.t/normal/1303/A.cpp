#include<bits/stdc++.h>
using namespace std;
int T,n,one;
char s[110];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),n=strlen(s),one=0;
		for(int i=0;i<n;i++)if(s[i]=='1')one++;
		if(!one){puts("0");continue;}
		one=n-one;
		for(int i=0;i<n;i++){
			if(s[i]=='1')break;
			one--;
		}
		for(int i=n-1;i>=0;i--){
			if(s[i]=='1')break;
			one--;
		}
		printf("%d\n",one);
	}
	return 0;
}