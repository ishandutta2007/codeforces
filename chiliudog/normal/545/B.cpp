#include <cstdio>
#include <cstring>
char s[200000],t[200000];
int m,n,i,j,k,l;
int main(){
	scanf("%s",s);
	scanf("%s",t);
	l=strlen(s);
	for(i=0;i<l;++i) if(s[i]!=t[i]) ++j;
	if(j&1) printf("impossible\n"); else {
		j>>=1;
		for(i=0;i<l;++i){
			if(s[i]!=t[i]){
				if((j--)>0) putchar(s[i]); else putchar(t[i]);
			}else putchar(s[i]);
		}
	}
	return 0;
}