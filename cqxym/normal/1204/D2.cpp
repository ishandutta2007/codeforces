#include<cstdio>
#include<string.h>
char c[100001],s[100001];
int main(){
	scanf("%s",c);
	int l=strlen(c),i,ct=0;
	for(i=l-1;i>-1;i--){
		if(c[i]=='0'){
			ct++;
			s[i]='0';
		}else if(ct>0){
			s[i]='1';
			ct--;
		}else{
			s[i]='0';
		}
	}
	for(i=0;i<l;i++){
		printf("%c",s[i]);
	}
	return 0;
}