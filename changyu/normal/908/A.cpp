#include<cstdio>
char c,k,d[128];
int main(){
	d['a']=d['e']=d['i']=d['o']=d['u']=1;
	while(~(c=getchar()))k+=c>47&&c<58&&c%2||d[c];
	printf("%d",k);
	return 0;
}