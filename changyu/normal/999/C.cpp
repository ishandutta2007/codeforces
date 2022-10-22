#include<cstdio>
int l,m,b[26],lt,ct;char c[400001];
int main(){
	scanf("%d%d%s",&l,&m,c);
	for(int i=0;i<l;i++)b[c[i]-97]++;
	for(;m>=b[lt];lt++)m-=b[lt];
	for(int i=0;i<l;i++){
	  if(!m&&c[i]==97+lt)putchar(c[i]);
	  if(c[i]==97+lt&&m)m--;
	  if(c[i]>97+lt)putchar(c[i]);
	}
	return 0;
}