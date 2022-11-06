#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int main(){
	int n,i,m;
	scanf("%d",&n);
	printf("%d\n",m=(n+2)/2);
	for(i=1;i<=n;++i){
		if(i<=m)printf("1 %d\n",i);
		else{
			printf("%d %d\n",i-m+1,m);
		}
	}
	return 0;
}