#include<bits/stdc++.h>
const int N=2e5+3;
int n,c[2];
char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s",a+1),n=strlen(a+1);
	c[0]=c[1]=0;
	for(int i=1;i<=n;i++)++c[a[i]-'0'];
	printf("%d\n",c[0]==c[1]?c[0]-1:std::min(c[0],c[1]));
	}return 0;
}