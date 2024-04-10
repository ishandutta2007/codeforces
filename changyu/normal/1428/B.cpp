#include<cstdio>
#include<cstring>
const int N=3e5+3;
char s[N];int n,c[3];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s",&n,s);
	c[0]=c[1]=c[2]=0;
	for(int i=0;i<n;i++)c[0]+=s[i]=='-'||s[(i+1)%n]=='-',c[1]+=s[i]=='<',c[2]+=s[i]=='>';
	if(!c[1]||!c[2])printf("%d\n",n);
	else printf("%d\n",c[0]);
	}return 0;
}