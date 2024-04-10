#include<stdio.h>
#define R register int
char s[100001];
inline void Solve(){
	char c=getchar();
	int len=1;
	while(c=='?'||c>='a'&&c<='z'){
		s[len]=c;
		c=getchar();
		len++;
	}
	s[len]='2';
	for(R i=1;i<len;i++){
		if(s[i]!='?'){
			if(s[i]==s[i-1]||s[i]==s[i+1]){
				puts("-1");
				return;
			}
		}else{
			if(s[i-1]=='a'&&s[i+1]=='b'||s[i-1]=='b'&&s[i+1]=='a'){
				s[i]='c';
			}else if(s[i-1]=='a'||s[i+1]=='a'){
				s[i]='b';
			}else{
				s[i]='a';
			}
		}
	}
	for(R i=1;i<len;i++){
		printf("%c",s[i]);
	}
	puts("");
}
int main(){
	s[0]='1';
	int t;
	scanf("%d\n",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}