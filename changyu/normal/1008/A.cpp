#include<cstdio>
const char v[5]={'a','e','i','o','u'}; 
int vowel(char a){
	if('a'==a||'e'==a||'i'==a||'o'==a||'u'==a)return 1;
	if(a=='n')return 0;
	return-1;
}
char a[101];
int main(){
	scanf("%s",a);
	for(int i=0;a[i];i++)
	  if(vowel(a[i])<0&&1!=vowel(a[i+1]))return 0*puts("NO"); 
	return 0*puts("YES");
}