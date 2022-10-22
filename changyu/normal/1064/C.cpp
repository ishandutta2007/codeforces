#include<cstdio>
const int N=1e5+1;
char a[N];int b[26];
int main(){
	scanf("%s%s",a,a);
	for(int i=0;a[i];i++)b[a[i]-97]++;
	for(int j=0;j<26;j++)
	  for(;b[j]--;)putchar(j+97);
	return 0;
}