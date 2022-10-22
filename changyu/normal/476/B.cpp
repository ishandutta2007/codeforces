#include<cstdio>
char s[11],a[11];int c,k,t,u;
int main(){
	scanf("%s%s",s,a);
	for(int i=0;s[i];i++)k+=s[i]=='+'?1:-1;
	for(int i=0;a[i];i++){
	  if(a[i]=='+')k--;else if(a[i]=='-')k++;
	  else c++;
	}
	for(int i=0;i<(1<<c);i++){
	  t=0;
	  for(int ii=i;ii;ii-=ii&-ii)t++;
	  if(k==t+t-c)u++;
	}printf("%.12lf",1.0*u/(1<<c));
	return 0;
}